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

void Solve() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i : a) cin >> i;
   int ans = 0;
   for (int i = 0; i + 1 < n; ++i) {
      int p = min_element(a.begin() + i, a.end()) - a.begin();
      ans += (p - i + 1);
      reverse(a.begin() + i, a.begin() + p + 1);
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
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}