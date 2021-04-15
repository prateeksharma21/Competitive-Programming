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
vector<string> a;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   a.resize(n);
   int w = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = 0; j < m; ++j) {
         w += (a[i][j] == 'o');
      } 
   }
   int ans = 0;

   int D = mdiv(1, 4);

   auto solve = [&](int value) {
      if (value == 2) {
         adds(ans, power(2, w - 2));
         return;
      }
      if (value % 2 == 0) {
         int f = w - 3;
         int t = (value - 2) / 2;
         int K = power(2, f + 2);
         muls(K, sub(1, power(D, t)));
         mdivs(K, 3);
         adds(ans, K);  
         adds(ans, power(2, w - value)); 
      } else {
         int f = w - 3;
         int t = (value - 2) / 2 + 1;
         int K = power(2, f + 2);
         muls(K, sub(1, power(D, t)));
         mdivs(K, 3);
         adds(ans, K);   
      }    
   };

   for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < m; ++j) {
         if (a[i][j] == '*') {
            cur = 0;
         } else {
            cur++;
            if (cur >= 2) {
               solve(cur);
            }
         }
      }
   }

   for (int i = 0; i < m; ++i) {
      int cur = 0;
      for (int j = 0; j < n; ++j) {
         if (a[j][i] == '*') {
            cur = 0;
         } else {
            cur++;
            if (cur >= 2) {
               solve(cur);
            }
         }
      }
   }


   cout << ans << '\n';
   return 0;
}