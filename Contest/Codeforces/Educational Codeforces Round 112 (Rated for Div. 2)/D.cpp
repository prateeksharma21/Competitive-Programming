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
const int MOD = 1e9+7, N = 2e5 + 10; 

int dp[N][10];
int n, m;
string s;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   cin >> n >> m >> s;
   string t = "abc";
   int c = 0;
   do {
      for (int i = 0; i < n; ++i) {
         dp[i + 1][c] = dp[i][c] + (s[i] != t[i % 3]);
      }
      ++c;
   } while (next_permutation(all(t)));
   // debug(c);
   while (m--) {
      int l, r;
      cin >> l >> r;
      int ans = 1e18;
      for (int i = 0; i < 6; ++i) {
         ans = min(ans, dp[r][i] - dp[l - 1][i]);
      }
      cout << ans << '\n';
   }
   return 0;
}