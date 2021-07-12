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
const int N = 400 + 10; 
int MOD;

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

int ways[N][N];
int pw2[N];
int dp[N];

int compute(int x, int y) {
   if (x < 0 or y < 0) return 0;
   int &ans = ways[x][y];
   if (ans != -1) return ans;
   if (x == 0 and y == 0) {
      return ans = 1;
   }
   ans = add(compute(x - 1, y), compute(x, y - 1));
   return ans;
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(ways, -1, sizeof ways);
   int n;
   cin >> n >> MOD;

   pw2[0] = 1;
   for (int i = 1; i < N; ++i) {
      pw2[i] = mul(2, pw2[i - 1]);
   }

   dp[1] = 1;
   dp[2] = 2;

   for (int k = 3; k <= n; ++k) {
      int ans = 0;
      for (int l = 1; l <= k; ++l) {
         for (int r = 1; r <= k; ++r) {
            if (l + r >= k) continue;
            int v = compute(l, r);
            muls(v, pw2[l - 1]);
            muls(v, pw2[r - 1]);
            int rem = (k - (l + r));
            if (rem % 2 == 0) continue;
            if (rem == 1)
               muls(v, dp[rem]);
            else 
               muls(v, dp[rem - 2]);
            debug(k, l, r, v);
            adds(dp[k], v);  
         }
      } 
      adds(dp[k], pw2[k - 1]);
      debug(k, dp[k]);
   }
   return 0;
}