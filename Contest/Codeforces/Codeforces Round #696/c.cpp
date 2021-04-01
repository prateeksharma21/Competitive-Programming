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
   vector<int> a(2 * n);
   for (int &i : a) {
      cin >> i;
   }
   sort(all(a));
   int mx = a.back();
   for (int i = 0; i < 2 * n - 1; ++i) {
      multiset<int> se;
      vector<array<int,2>> ops = {{mx, a[i]}};
      for (int j = 0; j < 2 * n - 1; ++j) {
         if (j != i) {
            se.insert(a[j]);
         }
      }
      int cur = mx;
      while (!se.empty()) {
         auto k = *prev(se.end());
         se.erase(prev(se.end()));
         auto f = se.find(cur - k);
         if (f == se.end()) break;
         se.erase(f);
         ops.push_back({k, *f});
         cur = k;
      }
      if (se.empty()) {
         cout << "YES\n";
         cout << mx + a[i] << '\n';
         for (auto [x, y] : ops) {
            cout << x << ' ' << y << '\n';
         }
         return;
      }
   }
   cout << "NO\n";
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