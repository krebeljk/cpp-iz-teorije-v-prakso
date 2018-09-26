#include <array>
#include <iostream>
#include "EBoard.hpp"

EBoard::EBoard() :
		matN_(7),
		state_(),
	    solState_{ 0,0,0 },
	    pegCount_(0),
	    exhausted_(false)
{
	for (int i = 0; i < matN_; i++)//vrsta
	{
		for (int j = 0; j < matN_; j++)//stolpec
		{

			// SL
			if (i < 2 && j < 2)
				state_[i][j] = -1;

			// SD
			if (i >= 5 && j < 2)
				state_[i][j] = -1;

			// ZL
			if (i < 2 && j >= 5)
				state_[i][j] = -1;

			// ZD
			if (i >= 5 && j >= 5)
				state_[i][j] = -1;
		}
	}
	
	state_[3][3] = 1;// 1-hole, 0-peg

	pegCount_ = countPegs();
}

void EBoard::printNum() {

	for (auto &row : state_)
	{
		for (auto &el : row)
		{
			std::cout << el;
		}

		std::cout << "\n";
	}
}

void EBoard::print() {

	for (auto &row : state_)
	{
		for (auto &el : row)
		{
			char rep = ' ';

			if (el == 0)
				rep = '.';

			if (el == 1)
				rep = 'o';

			std::cout << rep;
		}

		std::cout << "\n";
	}

}

int EBoard::countPegs() {

	int count = 0;

	for (auto &row : state_)
	{
		for (auto &el : row)
		{
			if (el == 0)
			{
				count++;
			}
		}
	}

	return count;
}


int EBoard::pegCount() {

	return pegCount_;
}


bool EBoard::nextHole() {

	// set to true when hole found (state == 0)
	bool found = false;

	// to prevent finding current state
	bool oldHole = true;

	int& I_start = solState_[0];
	int& J_start = solState_[1];

	// move through matrix
	for (int i = I_start; i<matN_; i++)
	{
		// in next row start from 0
		if (!oldHole)
			J_start = 0;

		for (int j = J_start; j < matN_; j++)
		{
			if (state_[i][j] == 1 && !oldHole)
			{
				found = true;

				// keep position
				solState_[0] = i;
				solState_[1] = j;
			}

			// after declining first attempt above
			if (oldHole)
				oldHole = false;

			// stop looking after found
			if (found)
				break;
		}

		// stop looking after found
		if (found)
			break;
	}

	return found;
}

void EBoard::makeNeighbours(int& I1, int& J1,
	                        int& I2, int& J2) {

	// set neighbour points in current direction
	switch (solState_[2])
	{
	case 0:	// dir 0: +J (next col)
		J1++;
		J2 += 2;
		break;
	case 1:	// dir 1: -I (prev row)
		I1--;
		I2 -= 2;
		break;
	case 2:	// dir 2: -J (prev col)
		J1--;
		J2 -= 2;
		break;
	case 3:	// dir 3: +I (next row)
		I1++;
		I2 += 2;
		break;
	default:
		std::cout << "ERROR: solState_[2] out of bounds in EBoard::validateCurrentDir()\n";
		break;
	}

}

bool EBoard::validMove() {

	// CREATE POINTS (indices of pegs)

	// here (hole index pair)
	int I0 = solState_[0];
	int	J0 = solState_[1];

	// init neighbours by copy
	auto I1 = I0; // neighbour 1
	auto J1 = J0; // neighbour 1
	auto I2 = I0; // neighbour 1
	auto J2 = J0; // neighbour 1

	makeNeighbours(I1, J1, I2, J2);

	// TEST VALIDITY

	// invalid move if out of matrix
	//point1
	if (I1 < 0 || !(I1 < matN_))
		return false;
	if (J1 < 0 || !(J1 < matN_))
		return false;
	//point1
	if (I2 < 0 || !(I2 < matN_))
		return false;
	if (J2 < 0 || !(J2 < matN_))
		return false;

	// invalid move if off-board
	if (state_[I1][J1] == -1)
		return false;
	if (state_[I2][J2] == -1)
		return false;

	// only valid if both neighbours are pegs
	// 0-peg
	// 1-hole
	if (state_[I1][J1] == 0 && state_[I2][J2] == 0)
		return true;

	//else invalid
	return false;
}

bool EBoard::updateMoveIntent() {
	// enter at lease once
	do {
		if (solState_[2] < 3) // can change direction clockwise
		{
			solState_[2]++; // next direction
		} // tried all directions for this hole
		else if (nextHole()) //moving to next hole (if it exists)
		{
			solState_[2] = 0;// reset direction
		}
		else // no next hole
		{
			exhausted_ = true;
			return false;
		}// move was incremented
	} while (!validMove()); // increment again if move not valid

	return true; // success
}

void EBoard::makeMove() {

	// CREATE POINTS (indices of pegs)

	// here (hole index pair)
	int I0 = solState_[0];
	int	J0 = solState_[1];

	// init neighbours by copy
	auto I1 = I0; // neighbour 1
	auto J1 = J0; // neighbour 1
	auto I2 = I0; // neighbour 1
	auto J2 = J0; // neighbour 1

	makeNeighbours(I1, J1, I2, J2);

	//put peg=0 here
	state_[I0][J0] = 0;

	//set neighbours to holes=1
	state_[I1][J1] = 1;
	state_[I2][J2] = 1;

	// lost a peg
	pegCount_--;

	// back to the start of move attempts
	solState_ = { 0, 0, 0 };
}

bool EBoard::exhausted() {

	return exhausted_;
}
