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

void give(int x, int y, int c) {
   cout << c + 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
   return;
} 

int Next() {
   int x;
   cin >> x;
   --x;
   return x;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<vector<array<int, 2>>> pos(2);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         pos[(i + j) % 2].push_back({i, j});
      }
   }

   for (int i = 0; i < n * n; ++i) {
      int st = Next();
      if (st != 0) {
         if (!pos[0].empty()) {
            auto [x, y] = pos[0].back();
            give(x, y, 0);
            pos[0].pop_back();
         } else {
            auto [x, y] = pos[1].back();
            if (st == 1)
               give(x, y, 2);
            else 
               give(x, y, 1);
            pos[1].pop_back();
         }
      } else {
         if (!pos[1].empty()) {
            auto [x, y] = pos[1].back();
            give(x, y, 1);
            pos[1].pop_back();
         } else {
            auto [x, y] = pos[0].back();
            give(x, y, 2);
            pos[0].pop_back();
         }
      }
   }
   return 0;
}