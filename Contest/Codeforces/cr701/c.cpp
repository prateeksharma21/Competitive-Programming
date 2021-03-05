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
   int x, y;
   cin >> x >> y;
   swap(x, y);
   int d = 1;
   int ans = 0;
   for (int st = 3, v = 3; v <= y; ) {
      int lst = min(y, (x + 1) * d);
      lst -= v;
      if (lst < 0) break;
      int t = lst / d + 1;
      ans += t;
      ++d;
      st += 2;
      v += st;
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