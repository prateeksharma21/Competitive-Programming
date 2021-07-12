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
const int MOD = 1e9+7, N = 510; 
const int INF = 1e18;

int n, m, k;
int d[N][N];
int cur[N][N];
int vis[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int c1[N][N];
int c2[N][N];

void dijkstra(int x, int y) {
   d[x][y] = 0;
   priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
   q.push({0, x, y});
   while (!q.empty()) {
      auto [D, x, y] = q.top();
      q.pop();
      if (D != d[x][y]) continue;
      if (x + 1 < n and cur[x + 1][y] and D + c2[x][y] < d[x + 1][y]) {
         d[x + 1][y] = D + c2[x][y];
         q.push({d[x + 1][y], x + 1, y});
      }
      if (x - 1 >= 0 and cur[x - 1][y] and D + c2[x - 1][y] < d[x - 1][y]) {
         d[x - 1][y] = D + c2[x - 1][y];
         q.push({d[x - 1][y], x - 1, y});
      }
      if (y + 1 < m and cur[x][y + 1] and D + c1[x][y] < d[x][y + 1]) {
         d[x][y + 1] = D + c1[x][y];
         q.push({d[x][y + 1], x, y + 1});
      }
      if (y - 1 >= 0 and cur[x][y - 1] and D + c1[x][y - 1] < d[x][y - 1]) {
         d[x][y - 1] = D + c1[x][y - 1];
         q.push({d[x][y - 1], x, y - 1});
      }
   }
}

int valid(int x, int y) {
   return x >= 0 and y >= 0 and x < n and y < m and !vis[x][y];
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m >> k;
   if (k & 1) {
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            cout << -1 << ' ';
         }
         cout << '\n';
      }
      return 0;
   }

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j + 1 < m; ++j) {
         cin >> c1[i][j];
      }
   }

   for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> c2[i][j];
      }
   }

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         for (int l = max(0LL, i - k / 2); l <= min(n - 1, i + k / 2); ++l) {
            for (int o = max(0LL, j - k / 2); o <= min(m - 1, j + k / 2); ++o) {
               d[l][o] = INF;
               cur[l][o] = 1;
               vis[l][o] = 0;
            }
         }

         dijkstra(i, j);

         vector<array<int, 2>> q;
         q.push_back({i, j});
         vis[i][j] = 1;

         vector<int> val(k + 1, INF);
         val[0] = 0;
         int ans = 1e18;
         for (int l = 1; l <= k / 2; l++) {
            vector<array<int, 2>> cur;
            while (!q.empty()) {
               auto [x, y] = q.back();
               q.pop_back();
               for (int v = 0; v < 4; ++v) {
                  int nx = x + dx[v], ny = y + dy[v];
                  if (valid(nx, ny)) {
                     cur.push_back({nx, ny});
                     vis[nx][ny] = 1;
                  }
               }
            }
            swap(q, cur);
            int rem = k % (2 * l);
            rem /= 2;
            int t = (k / (2 * l)) * 2;
            for (auto [x, y] : q) {
               assert(d[x][y] != INF);
               ans = min(ans, d[x][y] * t + val[rem]);
               val[l] = min(val[l], 2 * d[x][y]);
            }
            // debug(val);
            for (int o = 1; o < l; ++o) {
               for (int d = 0; d <= l / o; ++d) {
                  int rem = l - o * d;
                  val[l] = min(val[l], val[o] * d + val[rem]);
               }
            }
         }

         cout << ans << ' ';

         for (int l = max(0LL, i - k / 2 - 1); l <= min(n - 1, i + k / 2 + 1); ++l) {
            for (int o = max(0LL, j - k / 2 - 1); o <= min(m - 1, j + k / 2 + 1); ++o) {
               d[l][o] = INF;
               cur[l][o] = 0;
               vis[l][o] = 0;
            }
         }
      }
      cout << '\n';
   }
   return 0;
}