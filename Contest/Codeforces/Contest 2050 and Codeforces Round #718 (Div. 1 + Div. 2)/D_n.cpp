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
const int MOD = 1e9+7, N = 500 * 500 + 10; 
const int M = 510;
const int INF = LLONG_MAX;

vector<array<int, 2>> g[N];
int n, m, k;
int d[N][30];

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
      for (int j = 0; j < m - 1; ++j) {
         int x;
         cin >> x;
         g[i * m + j].push_back({i * m + j + 1, x});
         g[i * m + j + 1].push_back({i * m + j, x});
      }
   }
   for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j < m; ++j) {
         int x;
         cin >> x;
         g[i * m + j].push_back({(i + 1) * m + j, x});
         g[(i + 1) * m + j].push_back({i * m + j, x});
      }
   }
   for (int l = 1; l <= k / 2; ++l) {
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            int s = i * m + j;
            int mn = 1e18;
            for (auto [v, w] : g[s]) {
               mn = min(mn, d[v][l - 1] + 2 * w);
            }   
            d[s][l] = mn;
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         int s = i * m + j;
         cout << d[s][k / 2] << ' ';
      }
      cout << '\n';
   }
   return 0;
}