#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e4 + 10; 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

vector<int> G[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> vis(n+1);
   f(i,1,n+1){
      int x; cin >> x;
      G[x].push_back(i);
      G[i].push_back(x);
   }
   function<void(int)> dfs = [&](int u){
      vis[u] = 1;
      for(auto &v : G[u]){
         if(!vis[v]){
            dfs(v);
         }
      }
   };
   int ans = 0;
   f(i,1,n+1){
      if(!vis[i]){
         dfs(i),ans++;
      }
   }
   cout << ans << '\n';
   return 0;
} 