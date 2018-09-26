#include "EBoard.hpp"
#include <iostream> 

int main(){

	EBoard eb;

	eb.print();


    //std::cout << "Peg count: " << eb.pegCount() << "\n";

	std::cout << "make move\n";

	eb.nextValidMoveIntent();

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
