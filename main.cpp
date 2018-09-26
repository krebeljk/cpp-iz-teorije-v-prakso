#include "EBoard.hpp"
#include <iostream> 
#include <vector>

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
		
		if (loops % 1000000 == 0)
		{
			std::cout << "loops " << loops << "\n";
			std::cout << "moves " << ind << "\n";
		}

	}

	for (auto &st : seq)
	{
		st.print();
	}
	


// Output
//
//   ���
//   ���
// �������
// ���o���
// �������
//   ���
//   ���
//
// Peg count: 32  
  return 0;
}
