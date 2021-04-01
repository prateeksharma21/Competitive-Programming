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
   int cnt[3] = {};
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x % 3]++;
   }
   int req = n / 3;
   int ans = 0;

   auto val = [&](int i, int j) {
      if (i < j) {
         return j - i;
      } else {
         return 3 - (i - j);
      }
   };

   int op = 10;

   while (op--) {
      for (int i = 0; i < 3; ++i) {
         for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            if (cnt[i] > req and cnt[j] < req) {
               int mn = min(cnt[i] - req, req - cnt[j]);
               ans += mn * val(i, j);
               cnt[i] -= mn;
               cnt[j] += mn;
            }
         }
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