#include <iostream>
#include <ostream>

#include "InfoParser.hpp"

void clear() {
    std::cout << "\033[2J\033[3J\033[H";
}

int main() {
  std::cout << std::flush;
  InfoParser ip{};
  bool flag = true;
  while(flag) {
      clear();
      ip.update();
  }
}
