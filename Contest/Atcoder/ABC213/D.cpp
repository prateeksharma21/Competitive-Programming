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

vector<int> g[N];
vector<int> order;

void dfs(int u, int p = 0) {
   order.push_back(u);
   for (int v : g[u]) {
      if (v != p) {
         dfs(v, u);
         order.push_back(u);
      }
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
   for (int i = 1; i <= n; ++i) sort(all(g[i]));
   dfs(1);
   for (int i : order) cout << i << ' ';
   return 0;
}