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
const int MOD = 1e9+7, N = 1e4 + 10; 

int win[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   win[1] = 0;
   for (int i = 2; i < N; ++i) {
      for (int j = 2; j < i; ++j) {
         if (i % j == 0 and win[i - j] == 0) {
            win[i] = 1;
         }
      }
      if ((i & (i - 1)) == 0) {
         cout << i << ' ' << win[i] << '\n';
      } else {
         if (i % 2 == 0) {
            assert(win[i]);
         } else {
            assert(!win[i]);
         }
      }

   }
   return 0;
}