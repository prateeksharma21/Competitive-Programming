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

bool is_prime (int x) {
   if (x < 2 or (x > 2 and x % 2 == 0)) return false;
   for (int i = 3; i * i <= x; i += 2) {
      if (x % i == 0) {
         return false;
      }
   }
   return true;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout << 10000 << '\n';
   for (int i = 1; i <= 10000; ++i) {
      cout << 999999937 << ' ' << 999999937 << ' ' << 100 << '\n';
   }
   return 0;
}