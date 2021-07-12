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
const int MOD = 1e9+7, N = 5e3 + 10; 

int dp[N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> b[i];
   }
   vector<int> pre(n + 2), suff(n + 2);
   for (int i = 1; i <= n; ++i) {
      pre[i] = pre[i - 1] + a[i - 1] * b[i - 1];
   }
   for (int i = n; i >= 1; --i) {
      suff[i] = suff[i + 1] + a[i - 1] * b[i - 1];
   }
   int ans = pre[n];

   function<int(int, int)> solve = [&](int l, int r) {
      if (l > r) return 0LL;
      if (l == r) return a[l] * b[r];
      int ans = dp[l][r];
      if (ans != -1) return ans;
      ans = solve(l + 1, r - 1) + a[l] * b[r] + a[r] * b[l];
      return ans;
   };


   for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
         ans = max(ans, pre[i - 1] + suff[j + 1] + solve(i - 1, j - 1));
      }
   }
   cout << ans << '\n';
   return 0;
}