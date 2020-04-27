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
const int MOD = 998244353, N = 3e3 + 10; 

string s,t;
int n,m;
int dp[N][N];

int dfs(int l,int r){
   if(l>r) return 1;
   int &ans = dp[l][r];
   if(ans != -1) return ans;
   ans = 0;
   if(l>=m or s[r-l] == t[l]){
      ans += dfs(l+1,r);
      ans %= MOD;
   }
   if(r>=m or s[r-l] == t[r]){
      ans += dfs(l,r-1);
      ans %= MOD;
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> s >> t;
   n = s.length();
   m = t.length();
   memset(dp,-1,sizeof dp);
   int ans = 0;
   f(i,m-1,n){
      ans += dfs(0,i);
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
} 