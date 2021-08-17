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

void test(){
   int n, k;
   cin >> n >> k;
   vector<vector<int>> g(n + 1);
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      return;
   }

   auto solve = [&](vector<int> arr) {
      int n = arr.size();
      vector dp(n + 1, vector(n + 1, 0LL));
      
       int cur_sum = 0;
       for (int i = 1; i <= n; i++) {
           dp[1][i] = arr[i - 1];
           cur_sum += arr[i - 1];
           cur_sum %= MOD;
       }
       for (int i = 2; i <= k; i++) {
    
           // To store the elements of the current
           // row so that we will be able to use this sum
           // for subsequent values of k
           int temp_sum = 0;
    
           for (int j = 1; j <= n; j++) {
    
               // We will subtract previously computed value
               // so as to get the sum of elements from j + 1
               // to n in the (i - 1)th row
               cur_sum -= dp[i - 1][j];
               if (cur_sum < 0) cur_sum += MOD;
               cur_sum %= MOD;
               dp[i][j] = arr[j - 1] * cur_sum;
               dp[i][j] %= MOD;
               temp_sum += dp[i][j];
               temp_sum %= MOD;
           }
           cur_sum = temp_sum;
       }
       return cur_sum;
   };

   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      if (g[i].size() < k) continue;
      vector<int> par(n + 1);
      vector<int> vis(n + 1);
      vis[i] = 1;
      vector<vector<int>> val(n + 1);
      for (int v : g[i]) {
         queue<int> q;
         q.push(v);
         vis[v] = 1;
         vector<int> depth(n + 1);
         vector<int> comp;
         while (!q.empty()) {
            int u = q.front();
            q.pop();
            comp.push_back(u);
            for (int v : g[u]) {
               if (!vis[v]) {
                  depth[v] = depth[u] + 1;
                  q.push(v);
                  vis[v] = 1;
               }
            } 
         }
         // debug(comp, i);
         vector<int> cnt(n + 1);
         for (int v : comp) {
            cnt[depth[v]]++;
         }
         for (int i = 0; i <= n; ++i) {
            if (cnt[i]) {
               val[i].push_back(cnt[i]);
            }
         }
      } 
      for (int j = 0; j <= n; ++j) {
         if (val[j].size() < k) continue;
         // debug(val[j], i);
         ans += solve(val[j]);
         ans %= MOD;
      }
   }
   cout << ans << '\n';
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