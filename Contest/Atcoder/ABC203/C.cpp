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
   int n, k;
   cin >> n >> k;
   vector<array<int, 2>> a(n);
   for (auto &[x, y] : a) {
      cin >> x >> y;
   }
   sort(all(a));
   int cur = 0;
   for (auto &[x, y] : a) {
      if (cur + k < x) {
         cout << cur + k << '\n';
         return 0;
      }
      int d = x - cur;
      k -= d;
      k += y;
      cur = x;
   }
   cout << cur + k << '\n';
   return 0;
}