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
   int n;
   cin >> n;
   vector<int> A(n+1);
   for(int i = 1; i <= n; ++i) {
      cin >> A[i];
   }

   vector<int> parent(n+1), sz(n+1,1);
   iota(all(parent),0);

   vector<pair<int, int>> res;

   function<int(int)> find = [&](int u) {
      if(u == parent[u]) return u;
      return parent[u] = find(parent[u]);
   };

   function<void(int,int)> unite = [&](int u, int v) {
      res.push_back({u,v});
      u = find(u);
      v = find(v);
      if(u != v) {
         if(sz[v] > sz[u]) {
            swap(u,v);
         }
         parent[v] = u;
         sz[u] += sz[v];
      } else {
         res.pop_back();
      }
   };

   for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
         if(A[i] != A[j]) {
            unite(i,j);
         }
      }
   }

   if(res.size() != n-1) {
      cout << "NO\n";
      return;
   }

   cout << "YES\n";
   for(auto [x,y] : res) {
      cout << x << ' ' << y << '\n';
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
