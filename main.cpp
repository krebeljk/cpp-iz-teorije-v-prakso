#include "EBoard.hpp"
#include <iostream> 
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Timer.h"

int main(){
	
	//start stopwatch
	Timer t;

	std::array<EBoard,32> seq;

	// state index
	int ind = 0;

	seq[ind] = EBoard();

	seq[ind].print();

	// solution control
	bool solve = true;

	// count loops
	int loops = 0;

	while (solve)
	{
		if(seq[ind].nextValidMoveIntent())
		{ 
			ind++;
			seq[ind] = seq[ind-1];
			seq[ind].makeMove();
		}
		else if (ind>0)
		{
			ind--;
		}
		else
		{
			solve = false;
		}

		loops++;




	}


	std::cout << "Time elapsed: " << t.elapsed()/60 << " minutes\n";

// Output
//
//   ···
//   ···
// ·······
// ···o···
// ·······
//   ···
//   ···
//
// Peg count: 32  
  return 0;
}
