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
   int n, m;
   cin >> n >> m;
   vector<int> a(m);
   for (int i = 0; i < m; ++i) {
      cin >> a[i];
      --a[i];
   }
   set<int> val;
   vector<int> done(n);
   vector<vector<int>> pos(n);
   for (int i = 0; i < m; ++i) {
      pos[a[i]].push_back(i);
      if (done[a[i]]) continue;
      done[a[i]] = 1;
      val.insert(i);
   }
   int ans = *val.rbegin() + 1;
   for (int i = m - 1; i >= 0 and !val.empty(); --i) {
      int res = m - i;
      if (val.count(pos[a[i]].front())) {
         val.erase(pos[a[i]].front());
      }
      if (val.empty()) {
         ans = min(ans, res);
      } else {
         res += *val.rbegin() + 1;
         ans = min(ans, res);
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