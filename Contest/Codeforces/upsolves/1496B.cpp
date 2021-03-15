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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   vector<bool> present(n + 1);
   int mx = 0;
   for (int &i : a) {
      cin >> i;
      mx = max(mx, i);
      if (i <= n) present[i] = 1;
   }
   if (k == 0) {
      cout << n << '\n';
      return;
   }
   int mex = 0;
   while (present[mex]) ++mex;
   if (mx > mex) {
      int m = (mx + mex + 1) / 2;
      ++n;
      for (int i : a) {
         if (i == m) --n;
      }
      cout << n << '\n';
      return;
   }
   cout << n + k << '\n';
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