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
const int INF = 2e18;

void Solve() {
   int n, m;
   cin >> n >> m;
   set<array<int, 2>> se;
   for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      se.insert({l, r});
   }
   vector<int> res;
   for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      // debug(se);
      auto k = se.lower_bound({x, INF});
      if (k != se.begin()) {
         auto p = k;
         --p;
         auto [l, r] = *p;
         if (x >= l and x <= r) {
            res.push_back(x);
            se.erase(p);
            if (x - 1 >= l) {
               se.insert({l, x - 1});
            }
            if (x + 1 <= r) {
               se.insert({x + 1, r});
            }
            continue;
         }
      }
      if (k == se.end()) {
         auto p = k;
         p--;
         auto [l, r] = *p;
         res.push_back(r);
         se.erase(p);
         if (r - 1 >= l) se.insert({l, r - 1});
         continue;
      }
      if (k == se.begin()) {
         auto p = k;
         auto [l, r] = *p;
         res.push_back(l);
         se.erase(p);
         if (l + 1 <= r) se.insert({l + 1, r});
         continue;
      }
      auto nxt = k;
      auto prv = prev(k);
      auto [nl, nr] = *nxt;
      auto [pl, pr] = *prv;
      assert(x > pr and x < nl);
      if (x - pr <= nl - x) {
         res.push_back(pr);
         se.erase(prv);
         if (pr - 1 >= pl) se.insert({pl, pr - 1});
      } else {
         res.push_back(nl);
         se.erase(nxt);
         if (nl + 1 <= nr) se.insert({nl + 1, nr});
      }
   }
   // debug(se);
   for (int i : res) {
      cout << i << ' ';
   }
   cout << '\n';
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