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
   vector<int> a(n + 2);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   int ans = a[1];
   for (int i = 2; i <= n; ++i) {
      ans += abs(a[i] - a[i - 1]);
   }
   ans += a[n];
   for (int i = 1; i <= n; ++i) {
      if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
         int mx = max(a[i - 1], a[i + 1]);
         ans -= (a[i] - mx);
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