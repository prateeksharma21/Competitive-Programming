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
const int MOD = 1e9+7, N = 1e6 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   int lc = 1;
   for (int i = 1; i <= 16; ++i) {
      lc = lcm(lc, i);
   }
   int x;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> x;
         if ((i + j) & 1) {
            cout << lc + x * x * x * x << ' ';
         } else {
            cout << lc << ' ';
         }
      }
      cout << '\n';
   }
   return 0;
}