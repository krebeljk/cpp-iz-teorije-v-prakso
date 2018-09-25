#include "PegSolitaire.hpp"
#include <iostream> 

int main(){

  auto const english_board = get_english_board();

  print(english_board); // english_board->print(); ??
  std::cout << "Peg count: " << english_board.peg_count() << "\n";

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
