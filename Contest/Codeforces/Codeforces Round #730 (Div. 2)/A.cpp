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
   int a, b;
   cin >> a >> b;
   cout << abs(a - b) << ' ';
   if (a == b) {
      cout << 0 << '\n';
      return;
   }
   int mn = min(a, b);
   int d = abs(a - b);
   cout << min(mn % d, d - mn % d) << '\n';
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