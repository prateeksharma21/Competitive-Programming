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
   int n, m;
   cin >> n >> m;
   int x = 0, y = 0;
   string s[n];
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   int ans = (s[0][0] == '*');
   while (true) {
      vector<array<int, 3>> v;
      for (int i = x; i < n; ++i) {
         for (int j = y; j < m; ++j) {
            if (i == x and j == y) continue;
            if (s[i][j] == '*') {
               v.push_back({i - x + j - y, i, j});
            } 
         }
      }
      sort(all(v));
      if (v.empty()) break;
      ++ans;
      x = v.front()[1], y = v.front()[2];
   }
   cout << ans << '\n';
   return 0;
}