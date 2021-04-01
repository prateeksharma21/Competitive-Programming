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
const int MOD = 1e9+7, N = 1e3 + 10; 
vector<int> G[N];
set<int> depth[N];
int parent[N];
int mx;

pair<int, int> query(set<int> &q){
   cout << '?' << ' ' << q.size() << ' ';
   for(auto e : q){
      cout << e << ' ';
   }
   cout << endl;
   int x,d;
   cin >> x >> d;
   return {x,d};
}

void dfs(int u,int p = 0,int d = 0){
   depth[d].insert(u);
   mx = max(mx,d);
   parent[u] = p;
   for(auto v : G[u]){
      if(v != p){
         dfs(v,u,d+1);
      }
   }
}

void test(){
   int n;
   cin >> n;
   mx = 0;
   set<int> q;
   
   f(i,0,n+1){
      G[i].clear();
      depth[i].clear();
      if(i) q.insert(i);
   }

   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }

   pair<int, int> R = query(q);
   int root = R.first;
   int dist = R.second;

   dfs(root);

   debug(mx);

   int l = dist/2, r = min(mx,dist);
   int ans;
   while(l <= r){
      int m = (l+r)/2;
      pair<int, int> Q = {-1,-1};
      if(depth[m].size())
         Q = query(depth[m]);
      if(Q.second != dist){
         r = m-1;
      }else{
         l = m+1;
         ans = Q.first;
      }
   }

   f(i,0,n+1){
      depth[i].clear();
   }

   dfs(ans);
   int ss;

   if(depth[dist].size() > 1){
      ss = query(depth[dist]).F;
   }else{
      ss = *depth[dist].begin();
   }

   cout << "! "<< ans << ' ' << ss << endl;

   string s; cin >> s;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--) test();
   return 0;
} 