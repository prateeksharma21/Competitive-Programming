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
   }
   int res = 0;
   function<void(int, int, int)> dfs = [&](int idx, int sum, int dn) {
      if (idx == n) {
         res |= (sum == 0 and dn);
         return;
      }
      dfs(idx + 1, sum + a[idx], 1);
      dfs(idx + 1, sum - a[idx], 1);
      dfs(idx + 1, sum, dn);
   };
   dfs(0, 0, 0);
   cout << (res ? "YES\n" : "NO\n");
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