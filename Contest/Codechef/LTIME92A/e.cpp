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
const int MOD = 1e9+7, N = 3e2 + 10;
const int INF = 1e18;

int n, m;
vector<pair<int, int>> g[N];
int vis[N][N][N];
int cost[N][N][N];
int type[N];
int cp, cd;
int pp, pd;

void test(){
   cin >> n >> m;
   cin >> cp >> cd;
   cin >> pp >> pd;
   for (int i = 1; i <= n; ++i) {
      g[i].clear();
      for (int j = 0; j <= cp; ++j) {
         for (int k = 0; k <= cd; ++k) {
            vis[i][j][k] = false;
            cost[i][j][k] = INF;
         }
      }
   }

   for (int i = 1; i <= n; ++i) {
      cin >> type[i];
   }
   for (int i = 0; i < m; ++i) {
      int u, v, l;
      cin >> u >> v >> l;
      g[u].push_back({v, l});
   }

   priority_queue<array<int, 4>> Q;
   Q.push({0, 1, 0, 0});
   while (!Q.empty()) {
      auto [cst ,u, petrol, diesel] = Q.top();
      Q.pop();
      cst = -cst;
      if (vis[u][petrol][diesel]) continue;
      vis[u][petrol][diesel] = 1;
      cost[u][petrol][diesel] = cst;
      debug(u, petrol, diesel);
      if (type[u] == 1) {
         for (int p = petrol + 1; p <= cp; ++p) {
            Q.push({-cst - (p - petrol) * pp, u, p, diesel});
         }
      }
      if (type[u] == 2) {
         for (int d = diesel + 1; d <= cd; ++d) {
            Q.push({-cst - (d - diesel) * pd, u, petrol, d});
         }
      }
      if (type[u] == 3) {
         for (int p = petrol + 1; p <= cp; ++p) {
            for (int d = diesel + 1; d <= cd; ++d) {
               Q.push({-cst - (p - petrol) * pp - (d - diesel) * pd, u, p, d});
            }
         }
      }
      for (auto [v, l] : g[u]) {
         if (l > petrol + diesel) continue;
         for (int p = 0; p <= petrol; ++p) {
            int rd = l - p;
            if (rd <= diesel) {
               Q.push({-cst, v, petrol - p, diesel - rd});
            }
         }
         for (int d = 0; d <= diesel; ++d) {
            int rp = l - d;
            if (rp <= petrol) {
               Q.push({-cst, v, petrol - rp, diesel - d});
            }
         }
      }
   }
   int ans = INF;
   for (int petrol = 0; petrol <= cp; ++petrol) {
      for (int diesel = 0; diesel <= cd; ++diesel) {
         if (cost[n][petrol][diesel] < INF) {
            ans = min(ans, cost[n][petrol][diesel]);
         }
      }
   }
   if (ans == INF) {
      cout << "-1\n";
      return;
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