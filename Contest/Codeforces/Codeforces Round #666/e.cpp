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
const int MOD = 1e9+7, N = 1e6 + 10; 

int dp[N][2];
int a[N];
int n,r1,r2,r3,d;

int DP(int i,int st){
   int &ans = dp[i][st];
   if(ans != -1){
      return ans;
   }
   if(st == 0){
      if(i == n){
         ans = min(a[i]*r1+r3,min((a[i]+1)*r1,r2)+r1+2*d);
      }else{
         ans = min(a[i]*r1+r3+d+DP(i+1,0),min((a[i]+1)*r1,r2)+d+DP(i+1,1));
      }
   }else{
      if(i == n){
         ans = min(a[i]*r1+d+r1+r3,min((a[i]+1)*r1,r2)+2*d+2*r1);
      }else{
         ans = min(a[i]*r1+r3+3*d+r1+DP(i+1,0),min((a[i]+1)*r1,r2)+2*r1+3*d+DP(i+1,0));
      }
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> r1 >> r2 >> r3 >> d;
   for(int i = 1; i <= n; ++i){
      cin >> a[i];
   }
   memset(dp,-1,sizeof dp);
   cout << DP(1,0) << '\n';
   return 0;
} 