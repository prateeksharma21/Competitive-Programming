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
   int n, x;
   cin >> n >> x;
   for (int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      x -= c;
      if (i & 1)
      ++x;   
   }
   if (x >= 0) {
      cout << "Yes";
   } else {
      cout << "No";
   }
   return 0;
}