#include "EBoard.hpp"
#include <iostream> 
#include <vector>

int main(){

	std::vector<EBoard> seq{EBoard()};

	seq.back().print();
	


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
