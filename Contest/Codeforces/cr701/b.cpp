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
   int n, q, k;
   cin >> n >> q >> k;
   vector<int> a(n + 2);
   a[0] = 0, a[n + 1] = k + 1;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   vector<int> pre(n + 2);
   vector<int> val(n + 2);
   for (int i = 1; i <= n; ++i) {
      pre[i] = (a[i] - a[i - 1]) + (a[i + 1] - a[i]) - 2;
      val[i] = pre[i];
      pre[i] += pre[i - 1];
   }
   debug(pre);
   while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = pre[r] - pre[l - 1];
      ans -= (a[l] - a[l - 1] - 1);
      ans -= (a[r + 1] - a[r] - 1);
      ans += (a[l] - 1);
      ans += (k - a[r]);
      cout << ans << '\n';
   }
   return 0;
}