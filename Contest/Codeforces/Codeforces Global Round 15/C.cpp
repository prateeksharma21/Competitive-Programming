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
   vector<int> con(2 * n + 1);
   for (int i = 0; i < k; ++i) {
      int x, y;
      cin >> x >> y;
      con[x] = y;
      con[y] = x;
   }
   vector<int> rem;
   for (int i = 1; i <= 2 * n; ++i) {
      if (!con[i]) rem.push_back(i);
   }
   int o = n - k;
   for (int i = 0; i < o; ++i) {
      con[rem[i]] = rem[i + o];
   }
   int ans = 0;
   vector<int> done(2 * n + 1);
   for (int i = 1; i <= 2 * n; ++i) {
      if (done[i]) continue;
      set<int> s;
      for (int j = i + 1; j < con[i]; ++j) {
         if (!done[j]) continue;
         if (s.count(con[j])) {
            s.erase(con[j]);
         } else {
            s.insert(j);
         }
      }
      done[i] = done[con[i]] = 1;
      ans += s.size();
      // debug(s);
   }
   // debug(con);
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