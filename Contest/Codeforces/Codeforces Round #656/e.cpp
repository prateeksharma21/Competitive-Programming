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
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n,m;
   cin >> n >> m;
   
   vector<int> indeg(n+1);
   vector<vector<int>> G(n+1);
   vector<array<int,2>> ans,R;
   
   f(i,0,m){
      int t,x,y;
      cin >> t >> x >> y;
      if(t){
         G[x].pb(y);
         ++indeg[y];
         ans.pb({x,y});
      }else{
         R.pb({x,y});
      }
   }

   queue<int> q;
   f(i,1,n+1){
      if(!indeg[i]){
         q.push(i);
      }
   }

   vector<int> order;
   
   while(!q.empty()){
      int u = q.front();
      q.pop();
      order.pb(u);
      for(int v : G[u]){
         --indeg[v];
         if(!indeg[v]){
            q.push(v);
         }
      }
   }

   if(order.size() != n){
      cout << "NO\n";
      return;
   }
   
   cout << "YES\n";
   vector<int> pos(n+1);
   f(i,0,n){
      pos[order[i]] = i;
   }
   for(auto &e : R){
      if(pos[e[0]] > pos[e[1]]){
         swap(e[0],e[1]);
      }
      cout << e[0] << ' ' << e[1] << '\n';
   }
   for(auto i : ans){
      cout << i[0] << ' ' << i[1] << '\n'; 
   }
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
