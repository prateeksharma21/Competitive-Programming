#include <iostream>
#include <set>
#include <array>

const int N = 1e5;
int u[N];
int cnt[N];

int main() {
   int n;
   std::cin >> n;
   for (int i = 0; i < n; ++i) {
      std::cin >> u[i];
      --u[i];
   }
   std::set<std::array<int, 2>> s;
   int mx = 0;

   auto valid = [&]() {
      if (s.size() <= 1) return true;
      std::array<int, 2> F = *s.begin();
      std::array<int, 2> L = *s.rbegin();
      return F[0] == L[0];
   };

   for (int i = 0; i < n; ++i) {
      if (s.count({cnt[u[i]], u[i]})) s.erase({cnt[u[i]], u[i]});
      ++cnt[u[i]];
      s.insert({cnt[u[i]], u[i]});
      // remove mininum
      {
         std::array<int, 2> val = *s.begin();
         s.erase(s.begin());
         --val[0];
         if (val[0]) {
            s.insert(val);
         }
         if (valid()) mx = std::max(mx, i + 1);
         if (val[0]) {
            s.erase(val);
         }
         ++val[0];
         s.insert(val);
      }
      
      // remove maximum:
      {
         std::array<int, 2> val = *s.rbegin();
         s.erase(val);
         --val[0];
         if (val[0]) {
            s.insert(val);
         }
         if (valid()) mx = std::max(mx, i + 1);
         if (val[0]) {
            s.erase(val);
         }
         ++val[0];
         s.insert(val);
      }
   }
   std::cout << mx << '\n';
}