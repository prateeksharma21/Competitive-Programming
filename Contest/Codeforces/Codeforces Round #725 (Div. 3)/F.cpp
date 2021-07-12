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


// 1 -> 2, 2 -> 3, 3 -> 4, 4 -> 5, 5 -> 6, 6 -> 7

int solve(int n) {
   int mx = 1e10;
   int ans = 0;
   int sum = 0;
   for (int cur = 11; cur >= 1; --cur) {
      ans += (n / mx - sum) * cur;
      sum = n / mx;
      mx /= 10;
   }
   return ans;
}

void test(){
   int l, r;
   cin >> l >> r;
   cout << solve(r) - solve(l) << '\n';
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