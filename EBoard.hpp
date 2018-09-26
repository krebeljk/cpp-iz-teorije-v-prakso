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
	// dir - next move direction
	std::array<int, 3> solState_;

	// peg count - solution generation
	int pegCount_;

public:

	// Constructor
	EBoard();

	// print numbers
	void printNum();
	
	// print characters
	void print();

	// peg count
    int pegCount();

	// increment solState_
	void nextHole();
};

#endif