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
   vector a(n, vector(6, 0LL));
   vector<vector<int>> r(5);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
         cin >> a[i][j];
      }
      a[i][5] = i;
   }
   sort(all(a), [&](vector<int> x, vector<int> y){
      int c = 0;
      for (int i = 0; i < 5; ++i) {
         c += x[i] < y[i];
      }
      return c >= 3;
   });
   int cand = a[0][5] + 1;
   int valid = 1;
   for (int i = 1; i < n; ++i) {
      int res = 0;
      for (int j = 0; j < 5; ++j) {
         res += (a[0][j] < a[i][j]);
      }
      valid &= (res >= 3);
   }
   cout << (valid ? cand : -1) << '\n';
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