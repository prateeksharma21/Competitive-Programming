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

void test(){
   int n;
   cin >> n;
   vector<array<int, 2>> pts = {{1, 1}};
   vector<int> r(n), c(n);
   for (int i = 0 ; i < n; ++i) {
      cin >> r[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> c[i];
      pts.push_back({r[i], c[i]});
   }
   sort(all(pts));
   auto Dist = [&](int cx, int cy, int nx, int ny) {
      int dx = nx - cx;
      int dy = ny - cy;
      assert(dy <= dx);
      assert(dy >= 0);
      int v;
      if ((cx + cy) & 1) {
         v = (dx - dy + 1) / 2;
      } else {
         if (dy == dx) {
            v = dx;
         } else if (dy > 0) {
            v = min((dx + 1) / 2, (dx - dy) / 2);
         } else {
            v = dx / 2;
         }
      }
      return v;
   };
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      ans += Dist(pts[i - 1][0], pts[i - 1][1], pts[i][0], pts[i][1]);
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
      test();
   }
   return 0;
}