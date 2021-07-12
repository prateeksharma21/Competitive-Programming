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
const int LG = log2(N) + 1;

int lst[N];
int dp[N][LG];

struct SPF {
   int Mx;
   vector<int> spf;
   void init(int _N = N) {
      Mx = _N;
      spf.assign(Mx + 1, 0);
      for (int i = 2; i <= Mx; ++i) {
         if (!spf[i]) {
            spf[i] = i;
            for (int j = i * i; j <= Mx; j += i) {
               if (!spf[j]) spf[j] = i;
            }
         }
      }
   }
   vector<int> get(int x) {
      vector<int> res;
      while (spf[x]) {
         res.push_back(spf[x]);
         int p = spf[x];
         while (x % p == 0) {
            x /= p;
         }
      }
      return res;
   }
};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   SPF spf;
   spf.init();
   int n, q;
   cin >> n >> q;
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   vector<int> en(n + 10, -1);
   fill(lst, lst + N, n + 1);
   en[n + 1] = n;
   for (int i = n; i >= 1; --i) {
      vector<int> cur = spf.get(a[i]);
      int mn = 1e18;
      for (int v : cur) {
         mn = min(mn, lst[v]);
      }
      en[i] = min(mn - 1, en[i + 1]);
      dp[i][0] = en[i] + 1;
      for (int v : cur) {
         lst[v] = i;
      }
   }
   
   for (int j = 1; j < LG; ++j) {
      for (int i = 1; i <= n; ++i) {
         if (dp[i][j - 1] <= n) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
         } else {
            dp[i][j] = n + 1;
         }
      }
   }

   auto get = [&](int cur, int k) {
      for (int i = 0; i < LG; ++i) {
         if (k >> i & 1) {
            cur = dp[cur][i];
            if (cur > n) return cur;
         }
      }
      return cur;
   };


   while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = n;
      int L = 1, R = n;
      while (L <= R) {
         int m = (L + R) / 2;
         if (get(l, m) > r) {
            ans = m;
            R = m - 1;
         } else {
            L = m + 1;
         }
      }
      cout << ans << '\n';
   }

   return 0;
}