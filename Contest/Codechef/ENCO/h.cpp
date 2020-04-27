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
 
int vis[N];
int col[N];
int val[N];
vector<int> G[N];
int is;
vector<int> o;

void dfs(int u,int c = 0){
   vis[u] = 1;
   col[u] = c;
   o.pb(u);
   for(auto &v : G[u]){
      if(!vis[v]){
         dfs(v,c^1);
      }else{
         if(col[u] == col[v]){
            is = 0;
         }
      }
   }
}


void test(){
   int n,m;
   cin >> n >> m;
   f(i,1,n+1){
      G[i].clear();
      vis[i] = 0;
      col[i] = 0;
   }
   f(i,1,n+1){
      cin >> val[i];
   }
   f(i,0,m){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   if(m == 0){
      cout << "NOT POSSIBLE\n";
      return;
   }
   int ans = 0;
   int an = 0;
   f(i,1,n+1){
      if(!vis[i]){
         o.clear();
         is = 1;
         dfs(i);
         if(!is){
            cout << "NOT POSSIBLE\n";
            return;
         }
         int m1 = 0,m2 = 0;
         for(auto &e : o){
            if(col[e]){
               m1 += val[e];
            }else{
               m2 += val[e];
            }
         }
         ans += max(m1,m2);
         an += min(m1,m2);
      }
   }
   cout << "YES\n" << ans << '\n';
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
