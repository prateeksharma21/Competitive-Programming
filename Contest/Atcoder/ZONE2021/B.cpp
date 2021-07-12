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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, D, H;
   cin >> n >> D >> H;
   long double ans = 0;
   for (int i = 0; i < n; ++i) {
      int d, h;
      cin >> d >> h;
      long double x = D * h - d * H;
      x /= (D - d);
      ans = max(ans, x);
   }
   cout << setprecision(14) << fixed << ans << '\n';
   return 0;
}