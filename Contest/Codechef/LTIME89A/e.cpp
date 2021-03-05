#ifdef Prateek
  #include "\Prateek.h"
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
   int n, m;
   cin >> n >> m;
   vector<array<int,2>> A(m);
   vector<vector<int>> g(n+1);
   for(int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
      A[i] = {x, y};
   }

   map<pair<int,int>, bool> edge;
   map<int, bool> ff;
   vector<int> vis(n+1);
   int chk = true;

   function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      if(chk) {
         ff[u] = true;
      }
      for(int v : g[u]) {
         if(!vis[v]) {
            edge[{u, v}] = true;
            dfs(v);
         }
      }
   };

   for(int i = 1; i <= n; ++i) {
      if(!vis[i]) {
         dfs(i);
         chk = false;
      }
   }

   debug(ff);
   debug(edge);

   for(int i = 1; i <= n-1; ++i) {
      for(int j = 1; j <= n-i; ++j) {
         int u = i, v = i+j;
         if(edge[{u, v}]) {
            cout << "1 ";
            continue;
         }
         if(edge[{v, u}]) {
            cout << "0 ";
            continue;
         }
         if(ff[u] and ff[v]) {
            cout << rand()%2 << ' ';
            continue;
         }
         if(ff[u]) {
            cout << 1 << ' ';
            continue;
         }
         if(ff[v]) {
            cout << 0 << ' ';
            continue;
         }
         cout << rand()%2 << ' ';
      }
      cout << '\n';
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