#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 5e5 + 10; 

int n,m;
vector<int> G[N];
vector<int> P[N];
int A[N];
int vis[N];
int val[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   f(i,0,m){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   f(i,1,n+1){
      cin >> A[i];
      P[A[i]].pb(i);   
   }
   vector<int> R;
   f(i,1,n+1){
      for(auto &u : P[i]){
         int mx = 0;
         map<int,int> D;
         for(auto &v : G[u]){
            D[val[v]] = 1;
         }
         int v = G[u].size()+1;
         f(i,1,G[u].size()+2){
            if(!D[i]){
               v = i;
               break;
            }
         }
         if(v == i){
            val[u] = i;
            R.pb(u);
         }else{
            cout << "-1\n";
            return 0;
         }
      }
   }
   for(auto &e : R){
      cout << e << ' ';
   }
   cout << '\n';
   return 0;
} 