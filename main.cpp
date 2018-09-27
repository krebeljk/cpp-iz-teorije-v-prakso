#include "EBoard.hpp"
#include <iostream> 
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Timer.h"

int main(){
	
	//start stopwatch
	Timer t;

	std::array<EBoard, 32> seq;
	
	// level collections
	std::array<std::vector<EBoard>, 32> coll;
	
	// state index
	int ind = 0;

	seq[ind] = EBoard();

	// collect 0-level solution
	coll[ind].push_back(seq[ind]);

	seq[ind].print();

	// solution control
	bool solve = true;

	// count loops
	int loops = 0;

	//max level depth
	int depth = 0;

	while (solve)
	{
		if(seq[ind].nextValidMoveIntent())
		{ 

			ind++;
			std::cout << "lvl: " << ind << "\n";
			seq[ind] = seq[ind-1];
			seq[ind].makeMove();
			coll[ind].push_back(seq[ind]);//collect solution for level
			if (ind > depth) { depth = ind; };
		}
		else if (ind>0)
		{

			std::cout << "fail on lvl: " << ind << "\n";
			coll[ind].push_back(seq[0]);//spacing with initial state
			ind--;

		}
		else
		{
			solve = false;
		}

		seq[ind].print();

		loops++;

		if (loops > 50)
			break;




	}


	std::cout << "Time elapsed: " << t.elapsed()/60 << " minutes\n";

	std::cout << "RETURNING LEVEL COLLECTIONS:\n";

	for (int i = 0; i <= depth; i++) {

		std::cout << "LEVEL: " << i << "\n";

		for (auto& st : coll[i])
		{
			st.print();
		}
	}

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
