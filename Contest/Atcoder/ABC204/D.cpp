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

int a[105];
int dp[105][1005 * 105];

int dfs(int n, int w) {
   if (n == -1) return w == 0;
   if (w < 0) return 0;
   int &ans = dp[n][w];
   if (ans != -1) return ans;
   ans = (dfs(n - 1, w - a[n]) | (dfs(n - 1, w)));
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   int n;
   cin >> n;
   int sm = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sm += a[i];
   }
   int ans = 1e18;
   for (int i = 0; i <= sm; ++i) {
      if (dfs(n - 1, i)) {
         ans = min(ans, max(i, sm - i));
      }
   }
   cout << ans;
   return 0;
}