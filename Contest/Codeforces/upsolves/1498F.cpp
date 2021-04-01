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
const int K = 25;

int a[N];
vector<int> g[N];
int val[N][2 * K];
int can[N];
int n, k;

void dfs1 (int u, int p) {
   val[u][0] = a[u];
   for (int v : g[u]) {
      if (v == p) continue;
      dfs1 (v, u);
      for (int i = 1; i < 2 * k; ++i) {
         val[u][i] ^= val[v][i - 1];
      }
      val[u][0] ^= val[v][2 * k - 1];
   }
}

void dfs2 (int u, int p, vector<int> cur) {
   vector<int> fin(2 * k);
   for (int i = 0; i < 2 * k; ++i) {
      fin[i] = cur[i] ^ val[u][i];
   }
   int odd = 0;
   for (int i = k; i < 2 * k; ++i) {
      odd ^= fin[i];
   }
   can[u] = (odd > 0);
   for (int v : g[u]) {
      if (v == p) continue;
      vector<int> nxt = fin;
      for (int i = 1; i < 2 * k; ++i) {
         nxt[i] ^= val[v][i - 1];
      }
      nxt[0] ^= val[v][2 * k - 1];
      int L = nxt.back();
      for (int i = 2 * k - 1; i; --i) {
         nxt[i] = nxt[i - 1];
      }
      nxt[0] = L;
      dfs2(v, u, nxt);
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   dfs1(1, 0);
   dfs2(1, 0, vector<int>(2 * k));
   for (int i = 1; i <= n; ++i) {
      cout << can[i] << ' ';
   }
   return 0;
}