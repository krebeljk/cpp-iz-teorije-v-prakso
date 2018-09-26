#ifndef EBOARD_H
#define EBOARD_H

#include <array>
#include <iostream>

class EBoard
{
private:
	int maxX_;
	int maxY_;
	int thr_;

	using row_t = std::array<int, 7>;

	std::array<row_t, 7> state_;

public:

	// Constructor
	EBoard();

	// print numbers
	void printNum();
	
	// print characters
	void print();

	// peg count
    int pegCount();
	
};

#endif