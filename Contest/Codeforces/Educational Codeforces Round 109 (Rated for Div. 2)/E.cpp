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
const int MOD = 998244353, N = 22; 
const int M = 5e4 + 10;

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

int n, m;
int dp[1 << N][N];
int calc[1 << N][N];
int d[N][M];
int c[N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   prep_fact();
   cin >> n >> m;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> d[i][j];
         c[i][d[i][j]]++;
      }
   }

   for (int i = 1)


   for (int mask = 1; mask < (1 << n); ++mask) {
      for (int i = 0; i < n; ++i) {
         if (!(mask >> i & 1)) continue;
         int o = mask ^ (1 << i);
         if (o == 0) {
            dp[mask][i] = c[i][1];
         }
         for (int p = 0; p < n; ++p) {
            if (!(o >> p & 1)) continue;
            adds(dp[mask][i], dp[o][p] + mul(fact[__builtin_popcount(mask) - 1], c[i][__builtin_popcount(mask)]));
         }
         debug(i, mask, dp[mask][i], o);
      }
   }
   int ans = 0;
   int mask = (1 << n) - 1;
   for (int i = 0; i < n; ++i) {
      adds(ans, dp[mask][i]);
   }
   debug(ans);
   mdivs(ans, fact[n]);
   cout << ans << '\n';
   return 0;
}