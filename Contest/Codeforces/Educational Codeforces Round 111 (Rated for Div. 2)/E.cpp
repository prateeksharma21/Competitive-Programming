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
const int INF = 1e18;

int dp[1 << 18];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;

   vector<vector<int>> cnt(n + 1, vector<int>(k));
   for (int i = 0; i < n; ++i) {
      cnt[i + 1] = cnt[i];
      if (s[i] == '?') {
         for (int j = 0; j < k; ++j) cnt[i + 1][j]++;
      } else { 
         cnt[i + 1][s[i] - 'a']++; 
      }
   }

   auto can = [&](int v) {
      for (int i = 1; i < (1 << k); ++i) { 
         dp[i] = INF;
      }
      
      vector<vector<int>> pos(k);
      for (int i = 1; i + v - 1 <= n; ++i) {
         for (int j = 0; j < k; ++j) {
            if (cnt[i + v - 1][j] - cnt[i - 1][j] == v) {
               pos[j].push_back(i);
            }
         }
      }

      for (int mask = 1; mask  < (1 << k); ++mask) {
         for (int bit = 0; bit < k; ++bit) {
            if (!(mask >> bit & 1)) continue;
            int pmask = mask ^ (1 << bit);
            if (pmask == 0) {
               if (pos[bit].empty()) { 
                  return false;
               }
               dp[mask] = pos[bit].front() + v - 1;
               continue;
            } 
            auto L = upper_bound(all(pos[bit]), dp[pmask]);
            if (L != pos[bit].end()) {
               dp[mask] = min(dp[mask], *L + v - 1);
            }
         }
      }
      return dp[(1 << k) - 1] <= n;
   };


   int l = 0, r = n, ans;
   while (l <= r) {
      int m = (l + r) / 2;
      if (can(m)) {
         ans = m;
         l = m + 1;
      } else {
         r = m - 1;
      }
   }


   cout << ans << '\n';
   return 0;
}