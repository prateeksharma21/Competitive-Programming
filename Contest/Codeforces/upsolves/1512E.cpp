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
const int MOD = 1e9+7, N = 5e2 + 10; 

int dp[N][N];
int vis[N][N];
int n;
int val[N];
int a[N];

int dfs(int l, int r) {
   if (l == r) return dp[l][r] = a[l];
   int &ans = dp[l][r];
   int &visited = vis[l][r];
   if (visited) return ans;
   visited = 1;
   for (int i = l; i < r; ++i) {
      int L = dfs(l, i);
      int R = dfs(i + 1, r);
      if (L == R and L > 0) {
         return ans = L + 1;
      }
   } 
   return ans;
} 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   cin >> n;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   } 
   fill(val, val + N, MOD);
   val[0] = 0;
   for (int i = -1; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         if (dfs(i + 1, j) > 0) {
            val[j + 1] = min(val[j + 1], val[i + 1] + 1);
         }
      }
   }
   cout << val[n];
   return 0;
}