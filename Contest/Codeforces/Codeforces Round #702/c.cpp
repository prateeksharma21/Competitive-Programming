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

void test(){
   int x;
   cin >> x;
   for (int i = 1; i <= N; ++i) {
      int req = x - i * i * i;
      if (req <= 0) break;
      int l = 0, h = N;
      int ans;
      while (l <= h) {
         int m = (l + h) / 2;
         if (m * m * m <= req) {
            ans = m;
            l = m + 1;
         } else {
            h = m - 1;
         }
      }
      if (ans * ans * ans == req) {
         cout << "YES\n";
         return;
      }
   }
   cout << "NO\n";
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