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
   vector<array<int, 2>> a(n);
   for (auto &[x, y] : a) {
      cin >> x >> y;
   }
   sort(all(a), [&](array<int, 2> x, array<int, 2> y){
      return x[1] < y[1];
   });
   int r = n - 1;
   int done = 0;
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      if (a[i][0] == 0) break;
      int req = a[i][1] - done;
      while (r >= i and req > 0) {
         int mn = min(a[r][0], req);
         req -= mn;
         a[r][0] -= mn;
         ans += 2 * mn;
         done += mn;
         if (a[r][0] == 0) --r;
      }
      done += a[i][0];
      ans += a[i][0];
   }
   cout << ans << '\n';
   return 0;
}