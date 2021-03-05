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
   int n;
   cin >> n;
   vector<int> A(n+10);
   vector<int> pre(n+1);
   for(int i = 1; i <= n; ++i){
      cin >> A[i];
      pre[i] = pre[i-1]+A[i];
   }
   vector<vector<int>> dp(n+1,vector<int>(2,-1));

   function<int(int,int)> dfs = [&](int p,int ty){
      if(p >= n+1){
         return 0ll;
      }
      int &ans = dp[p][ty];
      if(ans != -1){
         return ans;
      }
      ans = 0;
      if(ty == 0){
         ans = min(dfs(p+1,1)+A[p],dfs(p+2,1)+A[p]+A[p+1]);
      }else{
         ans = min(dfs(p+1,0),dfs(p+2,0));
      }
      return ans;
   };

   // debug(dp);

   cout << dfs(1,0) << '\n';
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
