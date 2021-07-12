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
const int MOD = 1e9+7, N = 200 + 10; 

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

int dp[N][N];
int dist[N][N];

int calc(int x, int y) {
   if (x == 0) return 0;
   if (y == 0) return 1;
   int &ans = dp[x][y];
   if (ans != -1) return ans;
   ans = mdiv(add(calc(x - 1, y), calc(x, y - 1)), 2);
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         dist[i][j] = MOD;
      }
   }
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      dist[u][v] = 1;
      dist[v][u] = 1;
   }
   for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= n; ++j) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
         }
      } 
   }
   int ans = 0;
   for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
         for (int j = i + 1; j <= n; ++j) {
            int di = dist[k][i], dj = dist[k][j];
            int common = (di + dj - dist[i][j]) / 2;
            di -= common, dj -= common;
            adds(ans, calc(di, dj));
         }
      }
   }
   mdivs(ans, n);
   cout << ans << '\n';
   return 0;
}