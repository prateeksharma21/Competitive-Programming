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
const int MOD = 1e9+7, N = 2e5 + 10; 

int dp[N][4];
int vis[N][4];
int A[N];
int n;

int dfs(int ind,int skip){
   if(ind<=0) return 0;
   if(vis[ind][skip]){
      return dp[ind][skip];
   }
   vis[ind][skip] = 1;
   if(skip == 0){
      dp[ind][skip] = A[ind]+max({dfs(ind-2,0),dfs(ind-3,1),dfs(ind-4,2)});
   }else if(skip == 1){
      dp[ind][skip] = A[ind]+max(dfs(ind-2,1),dfs(ind-3,2));
   }else{
      dp[ind][skip] = A[ind]+dfs(ind-2,2);
   }
   return dp[ind][skip];
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   f(i,1,n+1){
      cin >> A[i];
   }
   if(n & 1){
      cout << max({dfs(n,0),dfs(n-1,1),dfs(n-2,2)});
   }else{
      cout << max(dfs(n,1),dfs(n-1,2));
   }
   return 0;
}