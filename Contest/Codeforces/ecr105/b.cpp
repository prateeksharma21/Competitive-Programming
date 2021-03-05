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
   int n;
   cin >> n;
   vector<int> a(4);
   for (int i = 0; i < 4; ++i) {
      cin >> a[i];
   }
   vector<array<int, 2>> A = {{0, 0}, {0, n - 1}, {n - 1, 0}, {n - 1, n - 1}};
   for (int i = 0; i < (1 << 4); ++i) {
      
      int u = a[0], r = a[1], d = a[2], l = a[3];

      auto apply = [&](int x, int y) {
         if (x == 0) {
            u--;
         } else {
            d--;
         }

         if (y == 0) {
            l--;
         } else {
            r--;
         }
      };

      for (int j = 0; j < 4; ++j) {
         if (i >> j & 1) {
            apply(A[j][0], A[j][1]);
         }
      }

      if (u >= 0 and r >= 0 and d >= 0 and l >= 0 and u < n - 1 and r < n - 1 and d < n - 1 and l < n - 1) {
         cout << "YES\n";
         return;
      }
   }
   cout << "NO\n";
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