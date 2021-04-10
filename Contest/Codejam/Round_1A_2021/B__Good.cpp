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
   int m;
   cin >> m;
   vector<int> a;
   for (int i = 0; i < m; ++i) {
      int x, v;
      cin >> x >> v;
      while (v--) {
         a.push_back(x);
      }
   } 
   sort(all(a));
   int n = a.size();
   int ans = 0;
   for (int i = 1; i < (1 << n); ++i) {
      int sum = 0;
      int pr = 1;
      for (int j = 0; j < n; ++j) {
         if (i >> j & 1) {
            sum += a[j];
         } else {
            pr *= a[j];
         }
      }
      if (sum == pr) {
         ans = max(ans, sum);
      }
   }
   cout << ans << '\n';
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