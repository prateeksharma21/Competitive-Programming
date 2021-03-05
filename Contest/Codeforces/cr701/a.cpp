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
   int ans = MOD;
   int a, b;
   cin >> a >> b;
   for (int i = 0; i < N; ++i) {
      if (b != 1) {
         int op = i, x = a;
         while (x) {
            x /= b;
            ++op;
         }
         ans = min(ans, op);
      }
      ++b;
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