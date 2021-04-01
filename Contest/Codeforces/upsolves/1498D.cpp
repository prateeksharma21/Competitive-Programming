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
const int Mx = 1e5;

int ans[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   fill(ans + 1, ans + N, MOD);
   for (int i = 0; i < n; ++i) {
      int t, x, y;
      cin >> t >> x >> y;
      vector<int> op(m + 1, 0);
      for (int j = 0; j <= m; ++j) {
         if (ans[j] != MOD) op[j] = y;
      }

      auto get = [&](int v) {
         if (t == 1) {
            return v + (x + Mx - 1) / Mx;
         } else {
            return (x * v + Mx - 1) / Mx;
         }
      };

      for (int j = 0; j <= m; ++j) {
         if (ans[j] == MOD or op[j] == 0) continue;
         int v = get(j);
         if (v > m) continue;
         ans[v] = min(ans[v], i + 1);
         op[v] = max(op[v], op[j] - 1);
      }
   }
   for (int i = 1; i <= m; ++i) {
      if (ans[i] == MOD) ans[i] = -1;
      cout << ans[i] << " ";
   }
   return 0;
}