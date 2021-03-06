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
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
   }
   int ans = 1e18;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (i == j) {
            ans = min(ans, a[i] + b[i]);
         } else {
            ans = min(ans, max(a[i], b[j]));
         }
      }
   }
   cout << ans << '\n';
   return 0;
}