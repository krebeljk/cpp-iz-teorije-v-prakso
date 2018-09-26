#include "EBoard.hpp"
#include <iostream> 

int main(){

	EBoard eb;

	eb.print();


    //std::cout << "Peg count: " << eb.pegCount() << "\n";

	std::cout << "dir vld: " << eb.validMove();

	std::cout << "make move\n";

	eb.updateMove();

	eb.makeMove();

	eb.print();



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
