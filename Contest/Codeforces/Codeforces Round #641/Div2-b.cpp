#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n;
   cin >> n;
   vector<int> dp(n+1),A(n+1);
   f(i,1,n+1){
      cin >> A[i];
   }
   int ans = 1;
   for(int i=n;i>=1;i--){
      dp[i] = 1;
      for(int j=i;j<=n;j+=i){
         if(A[j]>A[i]){
            dp[i] = max(dp[i],dp[j]+1);
         }
      }
      ans = max(ans,dp[i]);
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