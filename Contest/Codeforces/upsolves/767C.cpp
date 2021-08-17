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
const int MOD = 1e9+7, N = 1e6 + 10; 

vector<int> g[N];
int val[N];
int tin[N];
int tout[N];
int rev[N];
int timer;
int sz[N];
int siz[N];
int sum, r;

int dfs(int u, int p = 0) {
   sz[u] = val[u];
   siz[u] = 1;
   int fnd = 0;
   int ans = 0;
   rev[timer] = u;
   tin[u] = timer++;
   for (int v : g[u]) {
      if (v == p) continue;
      int nd = dfs(v, u);
      if (nd) {
         fnd = 1;
         ans = nd;
      }
      sz[u] += sz[v];
      siz[u] += siz[v];
   }
   if (fnd and sz[u] == 2 * sum / 3 and u != r) {
      cout << u << ' ' << ans << '\n';
      exit(0);
   } 
   tout[u] = timer;
   if (sz[u] == sum / 3) ans = u;
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      int p;
      cin >> p >> val[i];
      sum += val[i];
      if (p) g[p].push_back(i);
      else r = i;
   }
   if (sum % 3) return cout << -1,0;
   dfs(r);
   vector<int> val(n);
   debug(timer, n);
   for (int i = timer - 1; i >= 0; --i) {
      // cout << rev[i] << ' ' << sz[rev[i]] << ' ' << sum / 3 << '\n';
      // debug(val);
      if (sz[rev[i]] == sum / 3 and i + siz[rev[i]] < n and val[i + siz[rev[i]]]) {
         cout << rev[i] << ' ' << val[i + siz[rev[i]]] << '\n';
         return 0;
      }
      if (i + 1 < timer) val[i] = val[i + 1];
      if (sz[rev[i]] == sum / 3) {
         val[i] = rev[i];
      }
   }
   cout << -1 << '\n';
   return 0;
}