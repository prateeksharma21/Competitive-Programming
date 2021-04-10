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
using ld = long double;
const int MOD = 1e9+7, N = 1e5 + 10; 
const ld eps = 1e-9;

vector<vector<ld>> dp(N, vector<ld>(10));

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, d;
   cin >> n >> d;
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   sort(all(a));
   for (int i = 1; i <= n; ++i) {
      int v = a[i] % 10;
      dp[i] = dp[i - 1];
      dp[i][v] = max(dp[i][v], (ld)log((ld)a[i]));
      for (int j = 0; j < 10; ++j) {
         dp[i][(j * v) % 10] = max(dp[i][(j * v) % 10], dp[i - 1][j] + log((ld)a[i]));
      }
   }

   debug(dp[n][d]);

   if (dp[n][d] < eps) {
      cout << -1 << '\n';
      return 0;
   }
   vector<int> res;
   for (int i = n; i ; --i) {
      for (int j = 0; j < 10; ++j) {
         if ((j * a[i]) % 10 == d and dp[i][d] - (dp[i - 1][j] + log((ld)a[i])) < eps) {
            res.push_back(a[i]);
            d = j;
            break;
         }
      }
   }
   cout << res.size() << '\n';
   for (int i : res) {
      cout << i << ' ';
   }
   cout << '\n';
   return 0;
}