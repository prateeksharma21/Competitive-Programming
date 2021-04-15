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
const int MOD = 1e9+7, N = 1e5 + 10; 

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
   prep_fact();
   int n;
   cin >> n;
   vector<int> a(n);
   int sum = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
   }
   if (sum % n) {
      cout << 0 << '\n';
      return 0;
   }
   int avg = sum / n;
   int less = 0, more = 0, equal = 0;
   for (int i = 0; i < n; ++i) {
      less += (a[i] < avg);
      more += (a[i] > avg);
      equal += (a[i] == avg);
   }
   if (equal == n) {
      cout << 1 << '\n';
      return 0;
   }
   if (less == 1 or more == 1) {
      map<int, int> cnt;
      for (int i = 0; i < n; ++i) {
         cnt[a[i]]++;
      }
      int ans = fact[n];
      for (auto e : cnt) {
         muls(ans, ifact[e.second]);
      }
      cout << ans << '\n';
      return 0;
   }
   int ans = 2;
   {
      map<int, int> cnt;
      for (int i = 0; i < n; ++i) {
         if (a[i] < avg) {
            cnt[a[i]]++;
         }
      }
      muls(ans, fact[less]);
      for (auto e : cnt) {
         muls(ans, ifact[e.second]);
      }
   }
   {
      map<int, int> cnt;
      for (int i = 0; i < n; ++i) {
         if (a[i] > avg) {
            cnt[a[i]]++;
         }
      }
      muls(ans, fact[more]);
      for (auto e : cnt) {
         muls(ans, ifact[e.second]);
      }
   }
   {
      muls(ans, ncr(n, equal));
   }
   cout << ans << '\n';
   return 0;
}