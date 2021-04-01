#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 998244353 , N = 3e3 + 10; 

string s,t;
int dp[N][N];
int n,m;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> s >> t;
   n = s.length();
   m = t.length();
   s = '*'+s;
   t = '*'+t;
   for(int i=m;i<=n;i++){
      if(i>m or s[i] == t[m]){
         dp[i][0] = 1;
      }
      if(s[i] == t[1]){
         dp[i][1] = 1;
      }
   }
   for(int i=n;i>1;i--){
      for(int j=0;j<=n-i+1;j++){
         if(j+1>m or s[i-1] == t[j+1]){
            dp[i-1][j+1] += dp[i][j];
            dp[i-1][j+1] %= MOD;
         }
         int one = j+i-1;
         if(one>m or s[i-1] == t[one]){
            dp[i-1][j] += dp[i][j];
            dp[i-1][j] %= MOD;
         }
      }
   }
   int ans = 0;
   for(int j=0;j<=n;j++){
      ans += dp[1][j];
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
} 