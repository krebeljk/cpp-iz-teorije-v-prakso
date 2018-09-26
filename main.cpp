#include "EBoard.hpp"
#include <iostream> 
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int main(){

	std::vector<EBoard> seq{EBoard()};

	seq.back().print();

	// state index
	int ind = 0;

	// solution control
	bool solve = true;

	// count loops
	int loops = 0;

	while (solve)
	{
		if(seq[ind].nextValidMoveIntent())
		{ 
			seq.push_back(seq[ind]);
			ind++;
			seq[ind].makeMove();
		}
		else if (seq.capacity()>0)
		{
			seq.pop_back();
			ind--;
		}
		else
		{
			solve = false;
		}

		loops++;
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		//seq.back().print();
		
		if (loops % 10000 == 0)
		{
			std::cout << "loops " << loops << "\n";
			std::cout << "moves " << ind << "\n";
		}

		if (seq.back().pegCount() == 1)
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
