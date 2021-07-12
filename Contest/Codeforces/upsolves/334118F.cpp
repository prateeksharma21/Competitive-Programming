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
const int MOD = 1e9+7, N = 2e5 + 10; 

int val[N];
int par[N];
int d;
vector<int> g[N];

int query(int a, int b) {
   cout << a << ' ' << b << endl;
   cin >> a;
   return a;
}

void ans(int a) {
   cout << 3 << ' ' << a << endl;
   exit(0);
}

void dfs(int u, int p = 0, int dp = 0) {
   val[u] = 0;
   par[u] = p;
   if (dp >= d) return;
   for (int v : g[u]) {
      if (v == p) continue;
      dfs(v, u, dp + 1);
      val[u] = max(val[u], val[v] + 1);
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   d = query(1, 1);
   if (d == 0) {
      ans(1);
   }
   int u = 1;
   dfs(1);
   while (d) {
      vector<int> q;
      for (int v : g[u]) {
         if (v == par[u]) continue;
         if (val[v] >= d - 1) {
            q.push_back(v);
         }
      }
      if (q.size() == 1) {
         u = q.front();
      } else {
         u = query(2, u);
      }
      --d;
   }
   ans(u);
   return 0;
}