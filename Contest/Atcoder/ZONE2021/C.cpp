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
   int n;
   cin >> n;
   vector<int> a(n), b(n), c(n), d(n), e(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
   }
   int l = 1, r = 1e9;
   int ans = 1;

   auto valid = [&](int t) {
      vector<int> dp(32, 1e9);
      for (int i = 0; i < n; ++i) {
         int mask = 0;
         if (a[i] >= t) mask ^= 1;
         if (b[i] >= t) mask ^= 2;
         if (c[i] >= t) mask ^= 4;
         if (d[i] >= t) mask ^= 8;
         if (e[i] >= t) mask ^= 16;
         // debug(mask);
         dp[mask] = min(dp[mask], 1LL);
      }
      for (int k = 1; k < 32; ++k) {
         for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < 32; ++j) {
               if ((i | j) == k) {
                  dp[k] = min(dp[k], dp[i] + dp[j]);
               }
            }
         }
      }
      return dp[31] <= 3;
   };


   // valid(4);

   while (l <= r) {
      int m = (l + r) / 2;
      if (valid(m)) {
         ans = m;
         l = m + 1;
      } else {
         r = m - 1;
      }
   }

   cout << ans << '\n';
   return 0;
}