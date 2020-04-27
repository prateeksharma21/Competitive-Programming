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
const int MOD = 1e9+7, N = 2e5 + 10;
 
int n,m,a,b,c;
int p[N];
vector<int> G[N];
int dist[3][N];
int cnt;
int vis[N];
int pre[N];
int ans;

void bfs(int s){
   queue<int> q;
   q.push(s);
   vector<bool> used(n+1);
   used[s] = true;
   while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto &u : G[v]){
         if(!used[u]){
            used[u] = true;
            q.push(u);
            dist[cnt][u] = dist[cnt][v]+1;
         }
      }
   }
}

void dfs(int u){
   vis[u] = 1;
   int common = dist[1][u];
   int rem = dist[0][u]+dist[2][u];
   // cout << u << ' ' << common << ' ' << rem << '\n';
   if(rem+common<=m){
      ans = min(ans,pre[rem+common]+pre[common]);
   }
   for(auto v : G[u]){
      if(!vis[v]){
         dfs(v);
      }
   }
}

void test(){
   cin >> n >> m >> a >> b >> c;
   f(i,1,n+1){
      vis[i] = 0;
      G[i].clear();
   }
   f(i,1,m+1){
      cin >> p[i];
   }
   sort(p+1,p+m+1);
   f(i,1,m+1){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   cnt = 0;
   dist[cnt][a] = 0;
   bfs(a);
   cnt++;
   dist[cnt][b] = 0;
   bfs(b);
   cnt++;
   dist[cnt][c] = 0;
   bfs(c);
   pre[0] = 0;
   f(i,1,m+1){
      pre[i] = pre[i-1]+p[i];
   }
   ans = 1e18;
   dfs(b); 
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
