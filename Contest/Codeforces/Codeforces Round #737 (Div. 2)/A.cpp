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
   vector<int> a(n);
   int sum = 0, cur = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
   }
   sort(all(a));
   long double ans = -1e18;
   for (int i = 0; i + 1 < n; ++i) {
      sum -= a[i];
      cur += a[i];
      ans = max(ans, (long double)sum / (n - i - 1) + (long double)cur / (i + 1));
   }
   cout << setprecision(14) << fixed << ans << '\n';
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