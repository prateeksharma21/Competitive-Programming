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
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;
const int MOD = 1e9+7, N = 1e5 + 10; 
const int INF = 1e18;

int n, m;
vector<array<int, 3>> g[N];

struct Info{
   int dist;
   int node;
   int tim;
   int turn;

   Info(int a, int b, int c, int d) {
      dist = a;
      node = b;
      tim = c;
      turn = d;
   }

};

bool operator<(const Info& d1, const Info& d2) {
   if (d1.turn == 0 and d2.turn == 0) {
      return d1.dist < d2.dist;
   }
   if (d1.turn == 1 and d2.turn == 1) {
      return d1.dist > d2.dist;
   }
   return d1.dist > d2.dist;
}

int calc(int x) {
   priority_queue<Info> Q;
   Info st = Info(x, 1, x, 0);
   Q.push(st);
   vector<vector<int>> vis(n + 1, vector<int>(2));
   vector<vector<int>> dist(n + 1, vector<int>(2, INF));
   dist[1][0] = x;
   while (!Q.empty()) {
      auto [d, u, tm, turn] = Q.top();
      Q.pop();
      if (vis[u][turn]) continue;
      vis[u][turn] = 1;
      dist[u][turn] = d;
      for (auto [v, c, d] : g[u]) {
         Q.push({dist[u][turn] + c + d / (tm + 1) , v, tm + c + d / (tm + 1), turn ^ 1});
      }
   }
   return min(dist[n][0], dist[n][1]);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      g[a].push_back({b, c, d});
      g[b].push_back({a, c, d});
   }
   int l = 0, r = 1e18;
   while (r - l > 3) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      int v1 = calc(m1);
      int v2 = calc(m2);
      if (v1 > v2) {
         l = m1;
      } else {
         r = m2;
      }
   }
   int ans = 1e18;
   for (int i = l; i <= r; ++i) {
      ans = min(ans, calc(i));
   }
   if (ans == 1e18) {
      ans = -1;
   }
   cout << ans;
   return 0;
}
