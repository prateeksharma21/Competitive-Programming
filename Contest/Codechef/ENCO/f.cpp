#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
#define adj G
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1000 + 10; 
const int INF = 1e15;

int n,k,m,a;
int nodes[N];
int d[N][N];
vector<pii> G[N];

void dijkstra(int s) {
    d[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[s][v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[s][v] + len < d[s][to]) {
                d[s][to] = d[s][v] + len;
                q.push({d[s][to], to});
            }
        }
    }
}



int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k >> m >> a;
   f(i,1,a+1){
      cin >> nodes[i];
   }
   f(i,1,n+1){
      f(j,1,n+1){
         d[i][j] = INF;
      }
   }
   f(i,0,m){
      int u,v,w;
      cin >> u >> v >> w;
      G[u].pb({v,w});
      G[v].pb({u,w});
   }
   f(i,1,n+1){
      dijkstra(i);
   }
   f(i,1,a+1){
      f(j,i+1,a+1){
         if(d[nodes[i]][nodes[j]] < k){
            cout << "FAIL\n";
            return 0;
         }
      }
   }
   cout << "PASS\n";
   return 0;
}