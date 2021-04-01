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
   int v = 0;
   for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
         for (int k = 1; k <= 3; ++k) {
            for (int l = 1; l <= 3; ++l) {
               if ((i + j + k + l) & 1) {
                  ++v;
               }
            }
         }
      }
   }
   cout << v << '\n';
   return 0;
}