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
using ll = long long;
const int MOD = 1e9+7, N = 500 + 10;

int a[N];
int dp[N][N][N];
int n, x;

int dfs(int i, int X, int p) {
   if (i == n) return 0;
   int &ans = dp[i][X][p];
   if (ans != -1) return ans;
   ans = 1e6;
   if (a[i] >= p) {
      ans = min(ans, dfs(i + 1, X, a[i]));
      if (a[i] > X and X >= p) {
         ans = min(ans, 1 + dfs(i + 1, a[i], X));
      }
   }
   return ans;
}

void test(){
   cin >> n >> x;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i <= n + 1; ++i) {
      for (int j = 0; j <= 500; ++j) {
         for (int k = 0; k <= 500; ++k) {
            dp[i][j][k] = -1;
         }
      }
   }

   int res = dfs(0, x, 0);
   if (res == 1e6) res = -1;
   cout << res << '\n';

   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}