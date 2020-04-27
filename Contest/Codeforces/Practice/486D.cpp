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
const int MOD = 1e9+7, N = 2e3 + 10; 

int n,d,nd;
int A[N];
vector<int> G[N];
int dp[N];

void dfs(int u,int p){
   dp[u] = 1;
   for(auto &v : G[u]){
      if(v!=p){
         if(A[v]<A[nd] or A[v]>A[nd]+d) continue;
         if(A[v] == A[nd] and v<nd) continue;
         dfs(v,u);
         dp[u] *= (dp[v]+1);
         dp[u] %= MOD;
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> d >> n;
   f(i,1,n+1){
      cin >> A[i];
   }
   int u,v;
   f(i,1,n){
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   int ans = 0;
   f(i,1,n+1){
      nd = i;
      dfs(i,0);
      ans += dp[i];  
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
} 