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
const int MOD = 998244353, N = 500 + 10; 

namespace std {
 
template<class Fun>
class y_combinator_result {
   Fun fun_;
public:
   template<class T>
   explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
   template<class ...Args>
   decltype(auto) operator()(Args &&...args) {
      return fun_(std::ref(*this), std::forward<Args>(args)...);
   }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
   return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std

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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> a(n), v(n);
   for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      if (c == '+') {
         a[i] = 1;
         cin >> v[i];
      } else {
         a[i] = -1;
      }
   }
   int ans = 0;
   for (int x = 0; x < n; ++x) {
      if (a[x] == -1) continue;
      vector dp = vector(n + 1, vector(n + 1, -1LL));
      auto res = std::y_combinator([&](auto self, int i, int ctr) -> int {
         if (i == n) return 1LL;
         if (dp[i][ctr] != -1) return dp[i][ctr];
         int &ans = dp[i][ctr];
         ans = 0;
         if (i != x) adds(ans, self(i + 1, ctr));
         if (a[i] == 1) {
            if (i <= x and v[i] == v[x]) {
               adds(ans, self(i + 1, ctr + 1));
            } else if (v[i] < v[x]) {
               adds(ans, self(i + 1, ctr + 1));
            } else {
               adds(ans, self(i + 1, ctr));
            }
         } else {
            if (i < x) {
               adds(ans, self(i + 1, max(0LL, ctr - 1)));
            } else if (ctr >= 2) {
               adds(ans, self(i + 1, ctr - 1));
            }
         }
         return ans;
      })(0, 0);
      adds(ans, mul(res, v[x]));
   }
   cout << ans;
   return 0;
}