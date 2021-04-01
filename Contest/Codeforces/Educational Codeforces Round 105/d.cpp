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
const int MOD = 1e9+7, N = 5000 + 10; 

int a[N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   set<array<int, 3>> val;
   assert(n < 500);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
         if (i < j) {
            val.insert({a[i][j], i, j});
         }
      }
   }
   vector<int> sal(n);
   for (int i = 0; i < n; ++i) {
      sal[i] = a[i][i];
   }
   int nxt = n;
   vector<array<int, 2>> edges;
   while (!val.empty()) {
      set<int> nd;
      auto k = *val.begin();
      vector<array<int, 3>> improper;
      while (!val.empty() and (*val.begin())[0] == k[0]) {
         auto [_, x, y] = *val.begin();
         int chk = 1;
         for (int i : nd) {
            if (i != x)
               chk &= (a[i][x] == k[0]);
            if (i != y)
               chk &= (a[i][y] == k[0]);
         }
         if (chk) {
            nd.insert(x);
            nd.insert(y);
         } else {
            improper.push_back({_, x, y});
         }
         val.erase(val.begin());
      }
      for (array<int, 3> T : improper) {
         val.insert(T);
      }
      for (int i : nd) {
         edges.push_back({i, nxt});
      }
      vector<array<int, 3>> to_insert;
      vector<array<int, 3>> to_remove;
      for (auto [v, x, y] : val) {
         if (nd.count(x)) {
            a[nxt][y] = a[y][nxt] = v;
            to_insert.push_back({v, nxt, y});
            to_remove.push_back({v, x, y});
         }
         if (nd.count(y)) {
            a[x][nxt] = a[nxt][x] = v;
            to_insert.push_back({v, x, nxt});
            to_remove.push_back({v, x, y});
         }
      }
      for (array<int, 3> T : to_remove) {
         val.erase(T);
      }
      for (array<int, 3> T : to_insert) {
         val.insert(T);
      }
      sal.push_back(k[0]);
      ++nxt;
   }
   cout << nxt << '\n';
   for (int i : sal) {
      cout << i << ' ';
   }
   cout << '\n';
   cout << nxt << '\n';
   for (auto [x, y] : edges) {
      cout << x + 1 << ' ' << y + 1 << '\n';
   }
   return 0;
}