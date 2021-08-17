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
const int MOD = 998244353, N = 1e5 + 10; 
const int M = 55;

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

int dp[M][N];
int is[N];
int val[N];
int pre[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   vector<array<int, 2>> a(n);
   vector<int> l, r;
   for (auto &[x, y] : a) {
      cin >> x >> y;
      l.push_back(x);
      r.push_back(y);
   }
   auto get = [&](int l, int r) {
      l = max(l, 0LL);
      if (r < 0) return 0LL;
      if (l == 0) return pre[r];
      return sub(pre[r], pre[l - 1]);
   };

   for (int v = 1; v < N; ++v) {
      vector<int> L = l, R = r;
      int chk = 0;
      for (int i = 0; i < n; ++i) {
         L[i] = (L[i] + v - 1) / v;
         R[i] = R[i] / v;
      }
      pre[0] = 1;
      for (int sm = 1; sm * v <= m; ++sm) {
         pre[sm] = 1;
      }
      for (int i = 0; i < n; ++i) {
         for (int sm = 1; sm * v <= m; ++sm) {
            dp[i][sm] = get(sm - R[i], sm - L[i]);
         }
         pre[0] = 0;
         for (int sm = 1; sm * v <= m; ++sm) {
            pre[sm] = add(pre[sm - 1], dp[i][sm]);
         }
      }
      int res = 0;
      for (int sm = 1; sm * v <= m; ++sm) {
         adds(res, dp[n - 1][sm]);
      }
      val[v] = res;
   }
   int ans = val[1];
   for (int i = N - 1; i >= 2; --i) {
      subs(ans, val[i]);
      for (int j = 2; j * j <= i; ++j) {
         if (i % j == 0) {
            subs(val[j], val[i]);
            if (j * j != i) {
               subs(val[i / j], val[i]);
            }
         }
      }
   }
   cout << ans << '\n';
   return 0;
}