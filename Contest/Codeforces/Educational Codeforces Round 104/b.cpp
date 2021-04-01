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
   if (n % 2 == 0) {
      --k;
      k %= n;
      cout << k + 1 << '\n';
   } else {
      int m = (n + 1) / 2;
      int l = 1, r = 1e18;
      int ans = 0;
      while (l <= r) {
         int mid = (l + r) / 2;
         int f = mid / m;
         if (mid - f >= k) {
            ans = mid;
            r = mid - 1;
         } else {
            l = mid + 1;
         }
      }
      --ans;
      cout << (ans % n) + 1 << '\n';
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