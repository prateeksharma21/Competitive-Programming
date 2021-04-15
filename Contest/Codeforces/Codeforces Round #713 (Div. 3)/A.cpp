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
   map<int, int> c;
   map<int, int> ind;
   for (int i = 0, x; i < n; ++i) {
      cin >> x;
      ind[x] = i + 1;
      c[x]++;
   }
   for (auto e : c) {
      if (e.second == 1) {
         cout << ind[e.first] << '\n';
         return;
      }
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