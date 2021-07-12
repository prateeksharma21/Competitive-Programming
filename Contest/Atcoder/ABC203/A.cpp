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
   int a, b, c;
   cin >> a >> b >> c;
   if (a == b) {
      cout << c;
   } else if (b == c) {
      cout << a;
   } else if (a == c) {
      cout << b;
   } else {
      cout << 0;
   }
   return 0;
}