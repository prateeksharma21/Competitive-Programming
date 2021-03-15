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
   vector<int> a, b;
   for (int i = 0; i < 2 * n; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 0) {
         a.push_back(y * y);
      } else {
         b.push_back(x * x);
      }
   }
   debug(a, b);
   sort(all(a));
   sort(all(b));
   // sort(all(b), greater<int>());
   long double ans = 0;
   for (int i = 0; i < n; ++i) {
      ans += sqrt(a[i] + b[i]);
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