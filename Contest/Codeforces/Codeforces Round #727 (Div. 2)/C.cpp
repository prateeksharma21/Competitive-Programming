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
   int n, k, x;
   cin >> n >> k >> x;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   } 
   sort(all(a));
   vector<int> diff;
   int ans = 0;
   for (int i = 1; i < n; ++i) {
      if (a[i] - a[i - 1] > x) {
         ++ans;
         diff.push_back(a[i] - a[i - 1]);
      }
   }
   sort(all(diff));
   for (int i : diff) {
      int req = (i + x - 1) / x - 1;
      if (req <= k) {
         k -= req;
         --ans;
      } else {
         break;
      }
   }
   cout << ans + 1 << '\n';
   return 0;
}