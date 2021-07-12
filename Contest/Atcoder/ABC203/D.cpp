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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   vector a(n, vector(n, 0LL));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
      }
   } 

   auto valid = [&](int x) {
      vector<vector<int>> pre(n + 1, vector<int>(n + 1));
      for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= n; ++j) {
            pre[i][j] = (a[i - 1][j - 1] <= x) + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]; 
         }
      }

      auto sum = [&](int x1, int y1, int x2, int y2) {
         return pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1];
      };

      int mx = 0;
      for (int i = 1; i + k - 1 <= n; ++i) {
         for (int j = 1; j + k - 1<= n; ++j) {
            mx = max(mx, sum(i, j, i + k - 1, j + k - 1));
         } 
      }
      return mx >= (k * k + 1) / 2;
   };


   int l = 0, r = 1e9;
   int ans = -1;
   while (l <= r) {
      int m = (l + r) / 2;
      if (valid(m)) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }


   cout << ans << '\n';
   return 0;
}