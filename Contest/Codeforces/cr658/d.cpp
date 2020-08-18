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
   vector<int> a(2*n);
   f(i,0,2*n){
      cin >> a[i];
   }
   int mx = -1,cur = 0;
   vector<int> v;
   f(i,0,2*n){
      if(a[i] > mx){
         v.pb(cur);
         cur = 0;
      }
      mx = max(mx,a[i]);
      cur++;
   }
   v.pb(cur);
   debug(v);
   int sz = v.size();
   vector<vector<int>> dp(sz+1,vector<int>(n+1));
   f(i,0,sz+1) dp[i][0] = 1;
   f(i,1,sz+1){
      f(j,1,n+1){
         if(j < v[i-1]){
            dp[i][j] = dp[i-1][j];
         }else{
            dp[i][j] = (dp[i-1][j]|dp[i-1][j-v[i-1]]);
         }
      }
   }
   if(dp[sz][n]){
      cout << "YES\n";
   }else{
      cout << "NO\n";
   }
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
