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
   int p;
   cin >> p;
   for (int i = 2; i <= 100; ++i) {
      for (int j = i + 1; j <= 100; ++j) {
         if (p % i == p % j) {
            cout << i << ' ' << j << '\n';
            return;
         }
      }
   }
   assert(false);
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