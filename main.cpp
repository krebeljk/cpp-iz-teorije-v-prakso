#include "EBoard.hpp"
#include "Timer.h"
#include <chrono> // std::chrono::seconds
#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <vector>

int main() {

  // start stopwatch
  Timer t;

  std::array<EBoard, 32> seq;

  // state index
  int ind = 0;

  seq[ind] = EBoard();

  seq[ind].print();

  // solution control
  bool solve = true;

  // count loops
  int loops = 0;

  while (solve) {
    if (seq[ind].nextValidMoveIntent()) {
      ind++;
      seq[ind] = seq[ind - 1];
      seq[ind].makeMove();
    } else if (ind > 0) {
      ind--;
    } else {
      solve = false;
    }

    loops++;
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // seq.back().print();

    if (loops % 10000000 == 0) {
      std::cout << loops << "\n";
      std::cout << ind << "\n";
    }

    if (seq[ind].pegCount() == 1) {
      break;
    }
  }

  for (auto &st : seq) {
    st.print();
  }

  std::cout << "Time elapsed: " << t.elapsed() / 60 << " minutes\n";

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
