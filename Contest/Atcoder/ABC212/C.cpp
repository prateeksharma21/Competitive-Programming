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
   int n, m;
   cin >> n >> m;
   vector<int> a(n), b(m);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < m; ++i) {
      cin >> b[i];
   }
   sort(all(a));
   sort(all(b));
   int ans = 1e17;
   for (int i = 0; i < n; ++i) {
      auto k = lower_bound(all(b), a[i]) - b.begin();
      debug(k);
      if (k != m) ans = min(ans, abs(a[i] - b[k]));
      --k;
      if (k != -1) ans = min(ans, abs(a[i] - b[k]));
   }
   cout << ans;
   return 0;
}