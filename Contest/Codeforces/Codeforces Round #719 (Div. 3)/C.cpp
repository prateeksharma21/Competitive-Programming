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

void test(){
   int n;
   cin >> n;
   if (n == 2) {
      cout << -1 << '\n';
      return;
   }
   int c = 1;
   int ctr = 1;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (c) {
            cout << ctr << ' ';
         } else {
            cout << ctr << ' ';
         }
         ctr += 2;
         if (ctr > n * n) { 
            ctr = 2;
            c ^= 1;
         }
      }
      cout << '\n';
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}