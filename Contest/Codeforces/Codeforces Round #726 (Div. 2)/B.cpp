#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n, m, i, j;
   cin >> n >> m >> i >> j;
   vector<array<int, 2>> pt = {{1, 1}, {1, m}, {n, 1}, {n, m}};
   
   int mx = -1;

   vector<int> ans;

   auto solve = [&](array<int, 2> a, array<int, 2> b) {
      int d = abs(a[0] - i) + abs(a[1] - j) + abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(b[0] - i) + abs(b[1] - j);
      if (d >= mx) {
         ans = {a[0], a[1], b[0], b[1]};
         mx = d;
      }
   };


   for (auto a : pt) {
      for (auto b : pt) {
         solve(a, b);
      }
   }

   for (int i : ans) {
      cout << i << ' ';
   }
   cout << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}