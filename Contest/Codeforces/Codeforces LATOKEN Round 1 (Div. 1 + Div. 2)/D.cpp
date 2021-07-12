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

int n;

vector<int> query(int x) {
   vector<int> res(n + 1);
   cout << "? " << x << endl;
   for (int i = 1; i <= n; ++i) {
      cin >> res[i];
   }
   return res;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   vector<int> d = query(1);
   int cnt[2] = {0, 0};
   vector<int> level[n + 1];
   for (int i = 1; i <= n; ++i) {
      cnt[d[i] & 1]++;
      level[d[i]].push_back(i);
   }
   vector<array<int, 2>> edges;
   if (cnt[0] <= cnt[1]) {
      for (int i = 2; i <= n; ++i) {
         if (d[i] == 1) {
            edges.push_back({1, i});  
         }
      }
      for (int lvl = 2; lvl <= n; lvl += 2) {
         for (int nd : level[lvl]) {
            d = query(nd);
            for (int i = 1; i <= n; ++i) {
               if (d[i] == 1) {
                  edges.push_back({nd, i});  
               }
            }
         }
      }
   } else {
      for (int lvl = 1; lvl <= n; lvl += 2) {
         for (int nd : level[lvl]) {
            d = query(nd);
            for (int i = 1; i <= n; ++i) {
               if (d[i] == 1) {
                  edges.push_back({nd, i});  
               }
            }
         }
      }
   }
   cout << "!\n";
   for (auto &[x, y] : edges) {
      cout << x << ' ' << y << endl;
   }
   return 0;
}