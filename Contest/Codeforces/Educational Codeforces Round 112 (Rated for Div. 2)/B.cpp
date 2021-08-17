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

void test(){
   int n, m;
   cin >> m >> n;
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   int w, h;
   cin >> w >> h;
   if (w + x2 - x1 > m and h + y2 - y1 > n) {
      cout << -1 << '\n';
      return;
   }
   ld ans = 1e18;
   if (w + x2 - x1 <= m) {
      // debug("width");
      ld l = 0, r = min(x1, m - x2);
      ld val = r;
      while (r - l > eps) {
         ld md = (l + r) / 2;
         ld rem = md + max(x1, m - x2);
         if (rem >= w) {
            val = md;
            r = md;
         } else {
            l = md;
         }
      }
      ans = min(ans, val);
   }
   if (h + y2 - y1 <= n) {
      // debug("height");
      ld l = 0, r = min(y1, n - y2);
      // debug(l, r);
      ld val = r;
      while (r - l > eps) {
         ld md = (l + r) / 2;
         ld rem = md + max(y1, n - y2);
         if (rem >= h) {
            val = md;
            r = md;
         } else {
            l = md;
         }
      }
      ans = min(ans, val);   
   }
   cout << setprecision(14) << fixed << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}