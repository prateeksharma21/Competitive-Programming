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
const int MOD = 1e9+7, N = 1e5 + 1; 

vector<int> G[N];
vector<int> D(N);
vector<bool> vis(N);

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   f(i,1,N){
      if(2*i<N){
         G[i].pb(2*i);
      }
      if(i!=1){
         G[i].pb(i-1);
      }
   }
   queue<int> q;
   q.push(n);
   vis[n] = true;
   while(!q.empty()){
      int u = q.front();
      q.pop();
      for(auto &v : G[u]){
         if(!vis[v]){
            vis[v] = true;
            q.push(v);
            D[v] = D[u]+1;
         }
      }
   }
   cout << D[m] << '\n';
   return 0;
} 