#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 600 + 10; 

int g[N][N];
vector<array<int, 3>> edges;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      g[a][b] = c;
      edges.push_back({a, b, c});
   }
      
   return 0;
}