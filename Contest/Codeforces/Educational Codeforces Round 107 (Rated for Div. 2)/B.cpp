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
   int a, b, c;
   cin >> a >> b >> c;
   int v = pow(10, c - 1);
   int x = v;
   while (true) {
      if (to_string(x).length() == a) break;
      x *= 2;
   }
   int y = v;
   while (true) {
      if (to_string(y).length() == b) break;
      y *= 3;
   }
   debug(v);
   cout << x << ' ' << y << '\n';
   assert(gcd(x, y) == v);
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