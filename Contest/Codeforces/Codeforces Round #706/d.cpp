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
const int MOD = 998244353, N = 400 + 10; 

inline int add(int a, int b, int mod = MOD) {
  a += b; return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod = MOD) {
  a -= b; return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod = MOD) {
  return int((long long) a * b % mod);
}
inline int power(int base, long long ex, int mod = MOD) {
  int res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
  }
  return res;
}
inline int inv(int a, int mod = MOD) {
  return power(a, mod - 2, mod);
}
inline int mdiv(int a, int b, int mod = MOD) {
  return mul(a, power(b, mod - 2,  mod));
}
inline void adds(int &a, int b, int mod = MOD) {
  a += b; if (a >= mod) a -= mod;
}
inline void subs(int &a, int b, int mod = MOD) {
  a -= b; if (a < 0) a += mod;
}
inline void muls(int &a, int b, int mod = MOD) {
  a = int((long long) a * b % mod);
}
inline void mdivs(int &a, int b, int mod = MOD) {
  a = mdiv(a, b, mod);
}
vector<int> fact,ifact;
void prep_fact(int mx = 1e6 + 40) {
  fact.assign(mx,0);
  ifact.assign(mx,0);
  fact[0] = 1;
  for (int i = 1; i < mx; ++i) fact[i] = mul(i, fact[i - 1]);
  ifact[mx - 1] = inv(fact[mx - 1]);
  for (int i = mx - 1; i > 0; --i) ifact[i - 1] = mul(i, ifact[i]);
}
inline int ncr(int n, int r) {
  if (n < r || r < 0 || n < 0) return 0;
  return mul(fact[n], mul(ifact[n - r], ifact[r]));
}

vector<int> g[N];
vector<vector<int>> dist;
vector<array<int, 2>> Edge;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   dist = vector(n + 1, vector(n + 1, MOD));
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   for (int i = 1; i <= n; ++i) {
      queue<int> Q;
      Q.push(i);
      dist[i][i] = 0;
      while (!Q.empty()) {
         int u = Q.front();
         Q.pop();
         for (int v : g[u]) {
            if (dist[i][u] + 1 < dist[i][v]) {
               dist[i][v] = dist[i][u] + 1;
               Q.push(v);
            }
         }
      }
   }

   vector<int> val(n + 1);

   for (int i = 1; i <= n; ++i) {
      debug(dist[i]);
      map<int, int> done;
      vector<int> dp(n + 1, -1);
      vector<bool> vis(n + 1, false);
      int lf = 0;

      function<int(int)> dfs = [&](int u) {
         int &ans = dp[u];
         if (ans != -1) {
            return ans;
         }
         ans = 1;
         vis[u] = 1;
         int c = 0;
         for (int v : g[u]) {
            if (vis[v]) {
               if (dist[i][v] == dist[i][u] + 1) {
                  adds(ans, dfs(v));
                  ++c;
               }
            } else {
               if (dist[i][v] == dist[i][u] + 1) {
                  adds(ans, dfs(v));
                  ++c;
               }
            }
         }
         return ans;
      };


      val[i] = dfs(i);
      debug(dp);
      debug(lf);
      // val[i] /= lf;
   }
   debug(val);
   return 0;
}