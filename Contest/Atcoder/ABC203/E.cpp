#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
int N;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   N = n;
   vector<int> x(m), y(m);
   map<int, set<int>> sx, sy;
   map<array<int, 2>, int> mp;
   set<array<int, 2>> black;

   mp[{0, N}];
   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      black.insert({a, b});
      x[i] = a;
      y[i] = b;
      for (int dx = -1; dx <= 1; ++dx) {
         for (int dy = -1; dy <= 1; ++dy) {
            if (a + dx >= 0 and a + dx <= 2 * n and b + dy >= 0 and b + dy <= 2 * n) {
               sx[a + dx].insert(b + dy);
               sy[b + dy].insert(a + dx);
               mp[{a + dx, b + dy}];

               mp[{2 * n, b + dy}];
               sx[2 * n].insert(b + dy);
               sy[b + dy].insert(2 * n);
            }
         }
      }
   }
   int c = 1;
   for (auto &e : mp) {
      e.second = c++;
   }
   vector<vector<int>> g(c + 1);
   for (auto e : mp) {
      auto [x, y] = e.first;
      int v = e.second;
      if (black.count({x + 1, y - 1})) {
         g[v].push_back(mp[{x + 1, y - 1}]);
      }
      if (black.count({x + 1, y + 1})) {
         g[v].push_back(mp[{x + 1, y + 1}]);
      }
      auto k = sy[y].upper_bound(x);
      if (k != sy[y].end() and !black.count({*k, y})) {
         g[v].push_back(mp[{*k, y}]);
      }
   }
   int ans = 0;
   vector<int> vis(c + 1);
   queue<int> q;
   q.push({mp[{0, N}]});
   vis[mp[{0, N}]] = 1;
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
         if (!vis[v]) {
            vis[v] = true;
            q.push(v);
         }
      }
   }
   for (auto e : mp) {
      if (e.first[0] == 2 * N) {
         ans += vis[e.second];
      }
   }
   cout << ans;
   return 0;
}