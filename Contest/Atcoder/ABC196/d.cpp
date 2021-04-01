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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int h, w, a, b;
   cin >> h >> w >> a >> b;

   int ans = 0;
   map<vector<vector<int>>, bool> vis;


   function<void(vector<vector<int>>&, int)> solve = [&](vector<vector<int>> &grid, int ra) {
      if (vis[grid]) return;
      vis[grid] = 1;
      if (ra == 0) {
         ++ans;
         return;
      }
      auto check = [&](int x, int y) {
         return x >= 0 and x < h and y >= 0 and y < w and grid[x][y] == 0;
      };
      for (int i = 0; i < h; ++i) {
         for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 0) {
               if (ra) {
                  if (check(i + 1, j)) {
                     grid[i + 1][j] = grid[i][j] = 1;
                     solve(grid, ra - 1);
                     grid[i + 1][j] = grid[i][j] = 0;
                  }
                  if (check(i - 1, j)) {
                     grid[i - 1][j] = grid[i][j] = 1;
                     solve(grid, ra - 1);
                     grid[i - 1][j] = grid[i][j] = 0;      
                  }
                  if (check(i, j + 1)) {
                     grid[i][j + 1] = grid[i][j] = 2;
                     solve(grid, ra - 1);
                     grid[i][j + 1] = grid[i][j] = 0;
                  }
                  if (check(i, j - 1)) {
                     grid[i][j - 1] = grid[i][j] = 2;
                     solve(grid, ra - 1);
                     grid[i][j - 1] = grid[i][j] = 0;      
                  }
               }
            }
         }
      }
   };

   vector<vector<int>> grid(h, vector<int>(w));

   solve(grid, a);

   cout << ans << '\n';
   return 0;
}