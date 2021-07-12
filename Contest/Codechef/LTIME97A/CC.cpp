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
const int INF = 1e15;

void test(){
   int n, k;
   cin >> n >> k;
   vector<int> deg(n + 1);
   vector<vector<int>> g(n + 1);
   for (int i = 2; i <= n; ++i) {
      int p;
      cin >> p;
      g[p].push_back(i);
      g[i].push_back(p);
      deg[p]++;
      deg[i]++;
   }
   vector<int> sz(n + 1), par(n + 1);;

   vector<int> tin(n + 1);
   int timer = 0;

   function<void(int, int)> dfs = [&](int u, int p) {
      if (p) {
         g[u].erase(find(all(g[u]), p));
      }
      tin[u] = timer++;
      par[u] = p;
      sz[u] = 1;
      for (int v : g[u]) {
         dfs(v, u);
         sz[u] += sz[v];
      }
   };

   dfs(1, 0);

   vector<int> v(n);
   iota(all(v), 1LL);
   sort(all(v), [&](int a, int b){
      return tin[a] < tin[b];
   });

   vector<int> pos(n + 1);
   for (int i = 0; i < v.size(); ++i) {
      pos[v[i]] = i;
   }

   vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

   function<int(int, int)> calc = [&](int u, int rem) {
      if (rem < 0) return INF;
      int &ans = dp[u][rem];
      if (ans != -1) return ans;
      if (rem - sz[u] == 0) return ans = 1;
      ans = 2 + calc(1, rem - sz[u]);
      if (u != 1) {
         int ps = pos[u];
         int sub_sz = sz[u];
         if (ps + sub_sz < v.size()) {
            ans = min(ans, 1 + calc(v[ps + sub_sz], rem - sz[u]));
            ans = min(ans, calc(v[ps + sub_sz], rem));
         }
      }
      for (int v : g[u]) {
         ans = min(ans, calc(v, rem));
      }
      return ans;
   };

   int res = calc(1, k);

   assert(res != INF);

   cout << res << '\n';
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