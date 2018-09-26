#ifndef EBOARD_H
#define EBOARD_H

#include <array>
#include <iostream>

class EBoard
{
private:
	int matN_; // matrix size in x
	
	using row_t = std::array<int, 7>;

	// matrix holding state
	std::array<row_t, 7> state_;

	// solution state
	// (I, J, dir)
	// I - hole row 
	// J - hole column
	// dir - current move direction
	std::array<int, 3> solState_;

	// peg count - solution generation
	int pegCount_;

	// exhausted possible moves
	bool exhausted_;

	// Private methods

	// increment solState_ (false if no more holes)
	bool nextHole();

	// get neighbour indices based on solution state
	void makeNeighbours(int& I1, int& J1,
		                int& I2, int& J2);

	//count the pegs
	int countPegs();


public:

	// Constructor
	EBoard();

	// print numbers
	void printNum();
	
	// print characters
	void print();

	// peg count
    int pegCount();

	// update move intent (wish)
	// is false if exhausted
	bool nextValidMoveIntent();

	// is move valid
	bool validMove();

	// make move
	void makeMove();

	// exhausted
	bool exhausted();
	
};

#endif