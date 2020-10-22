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
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n,q;
   cin >> n >> q;
   vector<int> A(n);
   for(int i = 0; i < n; ++i) {
      cin >> A[i];
   }
   vector<vector<int>> dp(n+1,vector<int>(2));

   int mx1 = 0, mx0 = 0;
   int ans = 0;

   for(int i = n-1; i >= 0; --i){
      dp[i][0] = A[i];
      dp[i][0] = max(dp[i][0],A[i]+mx1);
      dp[i][1] = -A[i];
      dp[i][1] = max(dp[i][1],-A[i]+mx0);
      ans = max(ans,dp[i][0]);
      mx0 = max(mx0,dp[i][0]);
      mx1 = max(mx1,dp[i][1]);
      // cout << mx0 << ' ' << mx1 << '\n';
   }

   cout << ans << '\n';
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
