#include <iostream>

int main() {
   int64_t n;
   std::cin >> n;
   if (n == 0) {
      std::cout << 0 << '\n';
   } else if (n & 1) {
      std::cout << (n + 1) / 2 << '\n';
   } else {
      std::cout << n + 1 << '\n';
   }
}