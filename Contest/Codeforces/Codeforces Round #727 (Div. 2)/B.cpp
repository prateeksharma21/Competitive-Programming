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
   int n, q;
   cin >> n >> q;
   vector<vector<int>> cnt(n + 1, vector<int>(26));
   string s;
   cin >> s;
   for (int i = 1; i <= n; ++i) {
      cnt[i] = cnt[i - 1];
      cnt[i][s[i - 1] - 'a']++;
   }
   while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      for (int i = 0; i < 26; ++i) {
         ans += (cnt[r][i] - cnt[l - 1][i]) * (i + 1);
      }
      cout << ans << '\n';
   }
   return 0;
}