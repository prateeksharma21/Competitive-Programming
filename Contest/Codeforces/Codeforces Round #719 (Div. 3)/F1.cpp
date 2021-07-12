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

int query(int l, int r) {
   cout << "? " << l << ' ' << r << endl;
   int sum;
   cin >> sum;
   int n = r - l + 1;
   int z = n - sum;
   return z;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, t;
   cin >> n >> t;
   cin >> t;
   int l = 1, r = n;
   int ans = n;
   while (l <= r) {
      int m = (l + r) / 2;
      if (query(1, m) >= t) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }
   cout << "! " << ans << endl;
   return 0;
}