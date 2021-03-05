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
const int MOD = 1e9+7, N = 150000 + 100; 
const int INF = 1e16;

int n[4];
int a[4][N];
int cost[4][N];
vector<int> g[4][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   for (int i = 0; i < 4; ++i) cin >> n[i];
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < n[i]; ++j) {
         cin >> a[i][j];
         cost[i][j] = INF;
      }
   }
   for (int i = 0; i < 3; ++i) {
      int m;
      cin >> m;
      for (int j = 0; j < m; ++j) {
         int x, y;
         cin >> x >> y;
         --x, --y;
         g[i][x].push_back(y);
      }
   }
   set<array<int, 2>> cst;
   for (int i = 0; i < n[3]; ++i) {
      cost[3][i] = a[3][i];
      cst.insert({cost[3][i], i});
   }
   for (int i = 2; i >= 0; --i) {
      for (int j = 0; j < n[i]; ++j) {
         for (int k : g[i][j]) {
            cst.erase({cost[i + 1][k], k});
         }
         if (!cst.empty()) {
            cost[i][j] = a[i][j] + (*cst.begin())[0];
         }
         for (int k : g[i][j]) {
            cst.insert({cost[i + 1][k], k});
         }
      }
      cst.clear();
      for (int j = 0; j < n[i]; ++j) {
         cst.insert({cost[i][j] , j});
      }
   }
   int mn = (*cst.begin())[0];
   if (mn >= INF) mn = -1;
   cout << mn << '\n';
   return 0;
}