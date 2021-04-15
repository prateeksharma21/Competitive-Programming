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
   int n, c;
   cin >> n >> c;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<int> b(n - 1);
   for (int i = 0; i < n - 1; ++i) {
      cin >> b[i];
   }

   int l = 1, h = 1e18;
   int ans = -1;

   auto can = [&](int days) {
      int sum = days * a[0];
      int left = days;
      int cur = 0;
      for (int i = 1; i < n; ++i) {
         int req = max(0LL, b[i - 1] - cur);
         int days_req = (req + a[i - 1] - 1) / a[i - 1];
         if (left < days_req + 1) break;
         left -= days_req;
         --left;
         cur += a[i - 1] * days_req;
         assert(cur >= b[i - 1]);
         cur -= b[i - 1];
         sum = max(sum, cur + left * a[i]);
      }
      return sum >= c;
   };

   while (l <= h) {
      int m = (l + h) / 2;
      if (can(m)) {
         ans = m;
         h = m - 1;
      } else {
         l = m + 1;
      }
   }
   cout << ans << '\n';
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