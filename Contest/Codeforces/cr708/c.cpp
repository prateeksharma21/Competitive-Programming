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
   int n, k;
   cin >> n >> k;
   for (int i = 0; i < k - 3; ++i) {
      cout << 1 << ' ';
   }
   n = n - k + 3;
   if (n & 1) {
      cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
   } else {
      int m = n / 2;
      if (m & 1) {
         cout << m - 1 << ' ' << m - 1 << ' ' << 2 << '\n';
      } else {
         cout << m << ' ' << m / 2 << ' ' << m / 2 << '\n';
      }
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