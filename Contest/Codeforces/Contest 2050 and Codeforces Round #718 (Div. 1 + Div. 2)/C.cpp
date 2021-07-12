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
   int n;
   cin >> n;
   vector<int> p(n);
   vector<vector<int>> a(n, vector<int>(n));
   for (int i = 0; i < n; ++i) {
      cin >> p[i];
      --p[i];
      a[i][i] = p[i];
   }
   for (int i = 0; i < n - 1; ++i) {
      int x = i, y = 0;
      int mn = 1e18;
      vector<int> v;
      while (x < n) {
         v.push_back(a[x][y]);
         mn = min(mn, a[x][y]);
         ++x, ++y;
      }
      x = i + 1, y = 0;
      int c = 0;
      while (x < n) {
         if (v[c] == mn) {
            ++c;
            continue;
         }
         a[x][y] = v[c];
         ++c;
         ++x, ++y;
      }
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
         cout << 1 + a[i][j] << ' ';
      }
      cout << '\n';
   }
   return 0;
}