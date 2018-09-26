#include "EBoard.hpp"
#include <iostream> 
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int main(){

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
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		//seq.back().print();
		
		if (loops % 100000 == 0)
		{
			std::cout << "loops " << loops << "\n";
			std::cout << "moves " << ind << "\n";
		}

		if (seq[ind].pegCount() == 1)
		{
			break;
		}

	}

	for (auto &st : seq)
	{
		st.print();
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
