#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 5e3 + 10;

int T[N];
int nxt[N];
int parent[N];
int s[N];
int Mx[N], Mn[N];
int val[N];
int64_t dp[N];

void test(){
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      cin >> T[i];
   }   

   nxt[n] = n + 1;
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   s[n] = 0;

   for (int i = 0, j = 0; i < n; i = j) {
      while (j < n and T[i] == T[j]) ++j;
      int mx = -1e9, mn = 1e9;
      for (int k = i; k < j; ++k) {
         nxt[k] = j;
         mn = min(mn, s[k]);
         mx = max(mx, s[k]);
         parent[k] = i - 1;
      }
      for (int k = i; k < j; ++k) {
         Mx[k] = mx;
         Mn[k] = mn;
      }
   }

   dp[n + 2] = dp[n + 1] = dp[n] = 0;
   for (int i = n - 1; ~i; --i) {
      int nx = nxt[i];
      int nx_nx = nxt[nx];
      dp[i] = 0;
      int64_t L = 0;
      if (nx != n) {
         dp[i] = max(abs(s[i] - Mx[nx]), abs(s[i] - Mn[nx])) + dp[nx];
      } 
      if (parent[i] != -1) {
         if (parent[parent[i]] != -1) {
            for (int j = parent[parent[i]]; ~j; --j) {
               if (T[i] != T[j]) {
                  L = abs(s[i] - s[j]);
                  if (nx != n) {
                     L += max(abs(s[j] - Mx[nx]), abs(s[j] - Mn[nx]));
                     if (nx_nx != n) {
                        L += dp[nx_nx];
                     }
                  }
                  dp[i] = max(dp[i], L);
               }
            }
         }
      }
      if (i + 1 < n and T[i] == T[i + 1]) {
         dp[i] = max(dp[i + 1], dp[i]);
      }
   }

   cout << *max_element(dp, dp + n) << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}