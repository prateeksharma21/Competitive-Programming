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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   set<int> g[n + 1];
   for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v;
      g[u].insert(v);
      g[v].insert(u);
   }
   set<int> s;
   vector<int> cnt_more(n + 1);
   for (int i = 1; i <= n; ++i) {
      for (int v : g[i]) {
         cnt_more[i] += (v > i);
      }
      if (cnt_more[i] == 0) s.insert(i);
   }
   int q;
   cin >> q;
   while (q--) {
      int ty, u, v;
      cin >> ty;
      if (ty == 1) {
         cin >> u >> v;
         if (s.count(u)) s.erase(u);
         if (s.count(v)) s.erase(v);
         cnt_more[u] += (v > u);
         cnt_more[v] += (u > v);
         g[u].insert(v);
         g[v].insert(u);
         if (cnt_more[u] == 0) s.insert(u);
         if (cnt_more[v] == 0) s.insert(v);
      } else if (ty == 2) {
         cin >> u >> v;
         if (s.count(u)) s.erase(u);
         if (s.count(v)) s.erase(v);
         cnt_more[u] -= (v > u);
         cnt_more[v] -= (u > v);
         g[u].erase(v);
         g[v].erase(u);
         if (cnt_more[u] == 0) s.insert(u);
         if (cnt_more[v] == 0) s.insert(v);
      } else {
         cout << s.size() << '\n';
      }
   }
   return 0;
}