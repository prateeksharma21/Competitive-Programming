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
   int a, b;
   cin >> a >> b;
   a = a + b;
   int r;   
   if (a >= 15 and b >= 8) {
      r = 1;
   } else if (a >= 10 and b >= 3) {
      r = 2;
   } else if (a >= 3) {
      r = 3;
   } else {
      r = 4;
   }
   cout << r;
   return 0;
}