#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD =  998244353, N = 1e6 + 10; 

int cnt[N];

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

int rng[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   prep_fact();
   int n,k;
   cin >> n >> k;
   map<int,int> mp;
   vector<pair<int, int>> A(n);
   for(int i = 0; i < n; ++i){
      cin >> A[i].first >> A[i].second;
      mp[A[i].first];
      mp[A[i].second];
   }
   int c = 1;
   for(auto &i : mp){
      i.second = c++;
   }
   for(int i = 0; i < n; ++i){
      A[i] = {mp[A[i].first], mp[A[i].second]};
      cnt[A[i].first]++;
      rng[A[i].first]++;
      rng[A[i].second+1]--;
   }

   int cur = 0;
   for(int i = 0; i < c; ++i){
      cur += rng[i];
      rng[i] = cur;
   }

   int ans = 0;

   for(int i = 1; i < c; ++i) {
      if(cnt[i]){
         if(rng[i] >= k){
            int an = ncr(rng[i],k);
            subs(an,ncr(rng[i]-cnt[i],k));
            adds(ans,an);
         }
      }
   }

   cout << ans << '\n';
   return 0;
}