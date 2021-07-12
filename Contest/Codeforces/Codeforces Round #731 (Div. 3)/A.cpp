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
   int xa, ya, xb, yb, x, y;
   cin >> xa >> ya >> xb >> yb >> x >> y;
   int ans = abs(xa - xb) + abs(ya - yb);
   if (ans == 0) {
      cout << ans << '\n';
      return;
   }
   if (xa == xb and xa == x and min(ya, yb) <= y and y <= max(ya, yb)) ans += 2;
   else if (ya == yb and ya == y and min(xa, xb) <= x and x <= max(xa, xb)) ans += 2;
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