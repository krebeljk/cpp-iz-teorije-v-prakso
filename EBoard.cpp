#include <array>
#include <iostream>
#include "EBoard.hpp"

EBoard::EBoard() :
		matN_(7),
		state_(),
	    solState_{ 0,0,0 },
	    pegCount_(0)
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

	state_[3][3] = 1;
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

int EBoard::pegCount() {

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


void EBoard::nextHole() {

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
}
