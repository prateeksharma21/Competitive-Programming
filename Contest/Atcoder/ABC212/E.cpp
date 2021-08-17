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
const int MOD = 998244353, N = 5e3 + 10; 

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

int path[N][N];
int mat[N][N];
vector<int> g[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   prep_fact();
   int n, m, k;
   cin >> n >> m >> k;
   while (m--) {
      int u, v;
      cin >> u >> v;
      mat[u][v] = 1;
      mat[v][u] = 1;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   path[1][0] = 1;
   for (int len = 1; len <= k; ++len) {
      int sum = 0;
      for (int val = 1; val <= n; ++val) {
         adds(sum, path[val][len - 1]);
      }
      for (int val = 1; val <= n; ++val) {
         for (int j : g[val]) {
            subs(sum, path[j][len - 1]);
         }
         subs(sum, path[val][len - 1]);
         path[val][len] = sum;
         adds(sum, path[val][len - 1]);
         for (int j : g[val]) {
            adds(sum, path[j][len - 1]);
         }
      }
   }
   int ans = 0;
   for (int i = 2; i <= n; ++i) {
      if (!mat[i][1]) {
         adds(ans, path[i][k - 1]);
      }
   }
   cout << ans << '\n';
   return 0;
}