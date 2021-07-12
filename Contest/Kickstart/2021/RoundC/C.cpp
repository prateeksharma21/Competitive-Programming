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
using ld = double;
const int MOD = 1e9+7, N = 62;

int x;
ld e, w;
ld dp[N][N][N];
int vis[N][N][N];
int par[N][N][N];

ld dfs(int r, int p, int s) {
   int n = r + p + s;
   if (n == 1) {
      if (r) {
         par[r][p][s] = 0;
      } else if (p) {
         par[r][p][s] = 1;
      } else {
         par[r][p][s] = 2;
      }
      return (w + e) / 3;
   }
   ld val = 0;
   if (vis[r][p][s]) return dp[r][p][s];
   vis[r][p][s] = 1;
   if (r > 0) {
      ld k1 = dfs(r - 1, p, s) + (p * w + s * e) / (n - 1);
      if (k1 > val) {
         val = k1;
         par[r][p][s] = 0;
      }
   }
   if (p > 0) {
      ld k2 = dfs(r, p - 1, s) + (s * w + r * e) / (n - 1);
      if (k2 > val) {
         val = k2;
         par[r][p][s] = 1;
      }
   }
   if (s > 0) {
      ld k3 = dfs(r, p, s - 1) + (r * w + p * e) / (n - 1);
      if (k3 > val) {
         val = k3;
         par[r][p][s] = 2;
      }
   }
   return dp[r][p][s] = val;
}

void Solve() {
   cin >> w >> e;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         for (int k = 0; k < N; ++k) {
            vis[i][j][k] = 0;
         }
      }
   }

   ld mx = 0;
   array<int, 3> state;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         for (int k = 0; k < N; ++k) {
            if (i + j + k == 60) {
               if (mx < dfs(i, j, k)) {
                  mx = dfs(i, j, k);
                  state = {i, j, k};
               }
            }
         }
      }
   }
   string res = "";
   while (accumulate(all(state), 0LL) > 0) {
      auto &[r, p, s] = state;
      int n = r + p + s;
      int pa = par[r][p][s];
      res += (pa == 0 ? 'R' : (pa == 1 ? 'P' : 'S'));
      state[pa]--;
   }
   reverse(all(res));
   cout << res << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt >> x;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}