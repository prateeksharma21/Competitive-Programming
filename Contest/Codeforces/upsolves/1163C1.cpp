#include <iostream>
#include <map>
#include <array>
#include <algorithm>

const int N = 1000;

int n;
int x[N], y[N];

int sign (int x) {
   if (x >= 0) return 1;
   return -1;
}

int main() {

   std::cin >> n;
   for (int i = 0; i < n; ++i) {
      std::cin >> x[i] >> y[i];
   }

   int lines = n * (n - 1) / 2;
   int ans = lines * (lines - 1) / 2;

   std::map<std::array<int, 2>, int> slopes;

   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         int dy = abs(y[j] - y[i]);
         int dx = abs(x[j] - x[i]);
         int g = std::__gcd(dx, dy);
         dx /= g, dy /= g;
         dx *= sign(y[j] - y[i]) * sign(x[j] - x[i]);
         slopes[{dx, dy}]++;
      }
   }

   for (auto e : slopes) {
      ans -= e.second * (e.second - 1) / 2;
   }

   std::cout << ans << '\n';
}