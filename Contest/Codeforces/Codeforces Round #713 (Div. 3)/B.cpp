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
   int n;
   cin >> n;
   vector<string> s(n);
   vector<array<int, 2>> points;
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (int j = 0; j < n; ++j) {
         if (s[i][j] == '*') {
            points.push_back({i, j});
         }
      }
   }
   int x1 = points[0][0], y1 = points[0][1];
   int x2 = points[1][0], y2 = points[1][1];
   if (x1 == x2) {
      if (x1 + 1 < n) {
         s[x1 + 1][y1] = s[x1 + 1][y2] = '*';
      } else {
         s[x1 - 1][y1] = s[x1 - 1][y2] = '*';
      }
   } else if (y1 == y2) {
      if (y1 + 1 < n) {
         s[x1][y1 + 1] = s[x2][y1 + 1] = '*';
      } else {
         s[x1][y1 - 1] = s[x2][y1 - 1] = '*';
      }
   } else {
      s[x1][y2] = s[x2][y1] = '*';
   }
   for (int i = 0; i < n; ++i) {
      cout << s[i] << '\n';
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