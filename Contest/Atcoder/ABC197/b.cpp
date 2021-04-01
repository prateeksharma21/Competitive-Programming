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
   int n, m, x, y;
   cin >> n >> m >> x >> y;
   string s[n];
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   --x, --y;

   function<int(int,int,int,int)> solve = [&](int x, int y, int dx, int dy) {
      if (x < 0 or x >= n or y < 0 or y >= m or s[x][y] == '#') return 0LL;
      return 1 + solve(x + dx, y + dy, dx, dy);
   };

   debug(s[x][y]);

   cout << -3 + solve(x, y, 0, -1) + solve(x, y, 0, 1) + solve(x, y, -1, 0) + solve(x,  y, 1, 0);
   return 0;
}