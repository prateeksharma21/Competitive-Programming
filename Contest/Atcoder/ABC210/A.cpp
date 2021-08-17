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
   int n, a, x, y;
   cin >> n >> a >> x >> y;
   if (n > a) {
      cout << a * x + (n - a) * y;
   } else {
      cout << n * x;
   }
   return 0;
}