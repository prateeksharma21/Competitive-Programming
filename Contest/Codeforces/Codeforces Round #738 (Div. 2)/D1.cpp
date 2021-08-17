#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif

#include <atcoder/dsu>
using namespace atcoder;

#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m1, m2;
   cin >> n >> m1 >> m2;
   dsu d1(n), d2(n);
   for (int i = 0; i < m1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      d1.merge(u, v);
   }
   for (int i = 0; i < m2; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      d2.merge(u, v);  
   }
   vector<array<int, 2>> edge;
   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         if (!d1.same(i, j) and !d2.same(i, j)) {
            edge.push_back({i, j});
            d1.merge(i, j);
            d2.merge(i, j);
         }
      }
   }
   cout << edge.size() << '\n';
   for (auto [x, y] : edge) {
      cout << x + 1 << ' ' << y + 1 << '\n';
   }
   return 0;
}