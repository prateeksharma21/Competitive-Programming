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
   vector a(2 + 1, vector(n + 1, 0ll));
   auto pre = a;
   for (int i = 1; i <= 2; ++i) {
      for (int j = 1; j <= n; ++j) {
         cin >> a[i][j];
         pre[i][j] = pre[i][j - 1] + a[i][j];
      }
   }
   // debug(pre);
   int mn = 1e18;
   for (int i = 1; i <= n; ++i) {
      mn = min(mn, max(pre[1][n] - pre[1][i], pre[2][i - 1]));
      // debug(mn, pre[0][n], pre[0][i]);
   }
   cout << mn << '\n';
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