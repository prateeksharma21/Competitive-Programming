#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define adj G
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e3 + 10;
const int INF = 1e15;

vector<pii> G[N];
vector<pii> GG[N];
int dist[N];
int s;

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != dist[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                q.push({dist[to], to});
            }
        }
    }
}

int ways(int u,int d){
   if(u == s){
      return (d == 0);
   }
   int ans = 0;
   for(auto &v : GG[u]){
      if(dist[v.F]+v.S == dist[u]){
         ans += ways(v.F,d-v.S);
         // cout << 
      }
   }
   return ans;
}


void test(){
   int n,m;
   cin >> n >> m;
   f(i,1,n+1){
      G[i].clear();
      GG[i].clear();
      dist[i] = INF;
   }
   f(i,0,m){
      int u,v,w;
      cin >> u >> v >> w;
      G[u].pb({v,w});
      GG[v].pb({u,w});
   }
   int k;
   cin >> s >> k;
   dijkstra(s);
   if(dist[k] == INF){
      cout << "0\n";
      return;
   }
   cout << ways(k,dist[k]) << '\n';
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
