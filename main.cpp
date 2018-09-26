#include "EBoard.hpp"
#include <iostream> 

int main(){

	EBoard eb;

	eb.print();


    std::cout << "Peg count: " << eb.pegCount() << "\n";

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
