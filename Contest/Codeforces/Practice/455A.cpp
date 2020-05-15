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
const int MOD = 1e9+7, N = 1e5 + 10; 

int dp[N];
int A[N];
int cnt[N];

int dfs(int u){
   if(u<=0 or u>1e5) return 0;
   if(dp[u]!=-1) return dp[u];
   dp[u] = cnt[u]*u;
   dp[u] += max(dfs(u+2),dfs(u+3));
   return dp[u];
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   memset(dp,-1,sizeof dp);
   f(i,1,n+1){
      cin >> A[i];
      cnt[A[i]]++;
   }
   cout << max(dfs(1),dfs(2)) << '\n';
   return 0;
}