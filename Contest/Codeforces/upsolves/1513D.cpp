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
   int n, p;
   cin >> n >> p;
   vector<array<int, 3>> edge;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i + 1 < n; ++i) {
      edge.push_back({p, i, i + 1});
   }
   for (int i = 0; i < n; ++i) {
      int j = i + 1;
      while (j < n and a[j] % a[i] == 0) {
         edge.push_back({a[i], i, j});
         if (a[i] == a[j]) break;
         ++j;
      }
   }

   for (int i = n - 1; i >= 0; --i) {
      int j = i - 1;
      while (j >= 0 and a[j] % a[i] == 0) {
         edge.push_back({a[i], i, j});
         if (a[i] == a[j]) break;
         --j;
      }
   }

   vector<int> par(n);
   iota(all(par), 0LL);
   vector<int> sz(n);

   function<int(int)> find = [&](int u) {
      return u == par[u] ? u : par[u] = find(par[u]);
   };

   function<bool(int, int)> merge = [&](int u, int v) {
      u = find(u);
      v = find(v);
      if (u == v) return false;
      if (sz[u] < sz[v]) swap(u, v);
      sz[u] += sz[v];
      par[v] = u;
      return true;
   };

   sort(all(edge));

   int ans = 0;

   for (auto [w, x, y] : edge) {
      if (merge(x, y)) {
         ans += w;
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