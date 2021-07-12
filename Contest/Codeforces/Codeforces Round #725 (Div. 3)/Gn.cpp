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
const int Mx = 1e4;


void test(){
   int A, B, a, b;
   cin >> A >> B >> a >> b;

   int l = 0, r = 1e9;

   auto f = [&](int x) {
      if (a * x > A or b * x > B) return 0ll;
      int y = min((A - a * x) / b, (B - b * x) / a);
      return x + y;
   };

   while (r - l > Mx) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      int c1 = f(m1);
      int c2 = f(m2);
      if (c1 < c2) {
         l = m1;
      } else {
         r = m2;
      }
   }

   int ans = 0;
   for (int i = l; i <= r; ++i) {
      ans = max(ans, f(i));
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