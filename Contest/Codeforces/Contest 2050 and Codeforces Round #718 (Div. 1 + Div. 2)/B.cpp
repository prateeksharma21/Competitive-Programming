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
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n, m;
   cin >> n >> m;
   multiset<int> s[n];
   vector<vector<int>> a(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
         s[i].insert(a[i][j]);
      }
   }
   vector<vector<int>> vis(n, vector<int>(m));
   vector<vector<int>> b(n, vector<int>(m, -1));
   for (int k = 0; k < m; ++k) {
      int mn = 1e18;
      pair<int, int> ind = {-1, -1};
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            if (vis[i][j]) continue;
            if (a[i][j] < mn) {
               mn = a[i][j];
               ind = {i, j};
            }
         }
      }
      vis[ind.first][ind.second] = 1;
      b[ind.first][k] = mn;
      s[ind.first].erase(s[ind.first].find(mn));
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (b[i][j] == -1) {
            cout << *s[i].begin() << ' ';
            s[i].erase(s[i].begin());
         } else {
            cout << b[i][j] << ' ';
         }
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
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}