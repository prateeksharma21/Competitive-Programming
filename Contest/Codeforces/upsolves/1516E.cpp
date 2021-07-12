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
const int MOD = 1e9+7, N = 400 + 10; 

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

int ncr[N][N];
int dp[N][N];

void init() {
   ncr[0][0] = 1;
   for (int i = 1; i < N; ++i) {
      ncr[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
         ncr[i][j] = add(ncr[i - 1][j], ncr[i - 1][j - 1]);
      }
   }
}

int NCR(int n, int r) {
   if (n < r or r < 0 or n < 0) return 0;
   int res = 1;
   for (int i = n - r + 1; i <= n; ++i) {
      muls(res, i);
   }
   for (int i = 1; i <= r; ++i) {
      mdivs(res, i);
   }
   return res;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   init();
   for (int i = 1; i <= 2 * k; ++i) {
      dp[i][0] = 1;
      for (int j = 1; j <= 2 * k; ++j) {
         dp[i][j] = add(dp[i - 1][j], mul(i - 1, dp[i - 1][j - 1]));
      }
   }
   vector<int> ans(k + 1);
   ans[0] = 1;
   for (int j = 1; j <= k; ++j) {
      for (int i = 1; i <= min(n, 2 * j); ++i) {
         int s = 1;
         int val = 0;
         for (int f = 0; f <= i; ++f) {
            if (s) {
               adds(val, mul(ncr[i][f], dp[i - f][j]));
            } else {
               subs(val, mul(ncr[i][f], dp[i - f][j]));
            }
            s ^= 1;
         }
         val = mul(NCR(n, i), val);
         adds(ans[j], val);
      }
      if (j > 1) adds(ans[j], ans[j - 2]);
      cout << ans[j] << ' ';
   }
   cout << '\n';
   return 0;
}