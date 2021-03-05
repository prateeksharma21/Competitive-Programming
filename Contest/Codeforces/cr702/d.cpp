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
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
   }
   vector<int> depth(n);

   function<void(int, int, int)> find = [&](int l, int r, int d) {
      if (l > r) return;
      int mx = l;
      for (int i = l; i <= r; ++i) {
         if (a[i] > a[mx]) {
            mx = i;
         }
      }
      depth[a[mx]] = d;
      find(l, mx - 1, d + 1);
      find(mx + 1, r, d + 1);
   };

   find(0, n - 1, 0);
   
   for (int i = 0; i < n; ++i) {
      cout << depth[a[i]] << ' ';
   }
   cout << '\n';
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