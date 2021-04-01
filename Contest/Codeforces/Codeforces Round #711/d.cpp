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
const int M = 200 + 10;
const int Mx = 1e5;

int n, m;
int can[M][N];
vector<array<int, 3>> Q(n);

int dfs(int i, int cur) {
   if (cur >= N) return 1e18;
   if (i == n) return 1;

   int &ans = can[i][cur];

   if (ans != -1) return ans;

   ans = dfs(i - 1, cur);

   if (Q[i][0] == 1) {
      int x = Q[i][1];
      int y = Q[i][2];
      while (y--){
         cur += x;
         ans = min(ans, 1 + dfs(i + 1, cur));
      }
   } else {
      int x = Q[i][1];
      int y = Q[i][2];
      long double X = x;
      X /= Mx;
      while (y--) {
         cur = (cur * X);
         ans = min(ans, 1 + dfs(i + 1, cur));
      }
   }

   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   Q.resize(n);
   for (auto &[t, x, y] : Q) {
      cin >> t >> x >> y;
   }

   dfs(0, 0);

   for (int i = 1; i <= m; ++i) {
      int c = 1e18;
      for (int j = 0; j < n; ++j) {
         c = min(c, dfs(j, i));
      }
      cout << (c == 1e18 ? -1 : c) << '\n';
   }


   return 0;
}