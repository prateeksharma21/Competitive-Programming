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
const int MOD = 1e9+7, N = 5e6 + 10;

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<array<int, 4>> ops;
   for (int i = 0; i + 1 < n; i += 2) {
      ops.push_back({i + 1, i + 2, min(a[i], a[i + 1]), MOD});
   }
   cout << ops.size() << '\n';
   for (auto [i, j, x, y] : ops) {
      cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
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