#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9, N = 500 * 500 + 10; 

vector<array<int, 2>> g[N];
int d[N];
int T;

int dijkstra(int s) {
   fill(d, d + T, MOD);
   d[s] = 0;
   using pii = pair<int, int>;
   priority_queue<pii> q;
   q.push({0, s});
   while (!q.empty()) {
      int v = q.top().second;
      int d_v = -q.top().first;
      q.pop();
      if (d_v != d[v])
         continue;
      if (v == T - 1) return d_v;
      for (auto [to, len] : g[v]) {
         if (d[v] + len < d[to]) {
            d[to] = d[v] + len;
            q.push({-d[to], to});
         }
      }
   }
   return d[T - 1];
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int r, c;
   cin >> r >> c;
   T = r * c;

   auto get = [&](int x, int y) {
      return x * c + y;
   };

   vector A(r, vector(c - 1, 0));
   for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c - 1; ++j) {
         cin >> A[i][j];
         g[get(i, j)].push_back({get(i, j + 1), A[i][j]});
         g[get(i, j + 1)].push_back({get(i, j), A[i][j]});
      }
   }
   vector B(r - 1, vector(c, 0));
   for (int i = 0; i < r - 1; ++i) {
      for (int j = 0; j < c; ++j) {
         cin >> B[i][j];
         g[get(i, j)].push_back({get(i + 1, j), B[i][j]});
      }
   }
   for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
         for (int k = 1; k <= i; ++k) {
            g[get(i, j)].push_back({get(i - k, j), 1 + k});
         }
      }
   }
   cout << dijkstra(0) << '\n';
   return 0;
}