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

void Solve() {
   int g[3][3];
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         if (i == 1 and j == 1) continue;
         cin >> g[i][j];
      }
   }
   int ans = 0;
   ans += (2 * g[0][1] == g[0][0] + g[0][2]);
   ans += (2 * g[1][0] == g[0][0] + g[2][0]);
   ans += (2 * g[2][1] == g[2][0] + g[2][2]);
   ans += (2 * g[1][2] == g[0][2] + g[2][2]);
   map<int, int> cnt;
   {
      int d = g[0][1] + g[2][1];
      if (d % 2 == 0) cnt[d / 2]++;
   }
   {
      int d = g[1][0] + g[1][2];
      if (d % 2 == 0) cnt[d / 2]++;
   }
   {
      int d = g[0][0] + g[2][2];
      if (d % 2 == 0) cnt[d / 2]++;
   }
   {
      int d = g[0][2] + g[2][0];
      if (d % 2 == 0) cnt[d / 2]++;
   }
   int mx = 0;
   for (auto e : cnt) mx = max(mx, e.second);
   cout << ans + mx << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}