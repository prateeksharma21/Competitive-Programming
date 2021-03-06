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
   int n;
   cin >> n;
   long double ans = 0;
   for (int i = 1; i < n; ++i) {
      ans += n * 1.0 / i;
   }
   cout << setprecision(14) << fixed << ans << '\n';
   return 0;
}