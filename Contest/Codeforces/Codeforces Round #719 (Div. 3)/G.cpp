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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, w;
vector<vector<int>> a;

vector<int> bfs(int x, int y) {
   vector<int> d(n * m, INF), vis(n * m);
   d[x * m + y] = 0;
   vis[x * m + y] = 1;
   queue<array<int, 2>> Q;
   Q.push({x, y});

   auto valid = [&](int x, int y) {
      return x >= 0 and x < n and y >= 0 and y < m and !vis[x * m + y] and a[x][y] != -1;
   };

   while (!Q.empty()) {
      auto [x, y] = Q.front();
      Q.pop();
      for (int i = 0; i < 4; ++i) {
         int nx = x + dx[i], ny = y + dy[i];
         if (valid(nx, ny)) {
            d[nx * m + ny] = d[x * m + y] + 1;
            vis[nx * m + ny] = 1;
            Q.push({nx, ny});
         }
      }
   }

   return d;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m >> w;
   a = vector(n, vector(m, 0LL));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   vector<int> d1 = bfs(0, 0);
   vector<int> d2 = bfs(n - 1, m - 1);
   int ans = INF;
   if (d1[n * m - 1] != INF) ans = d1[n * m - 1] * w;
   int f = INF, s = INF;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (a[i][j] > 0 and d1[i * m + j] != INF) {
            f = min(f, d1[i * m + j] * w + a[i][j]);
         }
         if (a[i][j] > 0 and d2[i * m + j] != INF) {
            s = min(s, d2[i * m + j] * w + a[i][j]);
         }
      }
   }
   ans = min(ans, f + s);
   ans = (ans == INF ? -1 : ans);
   cout << ans << '\n';
   return 0;
}