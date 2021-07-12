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
   vector<int> u(n);
   vector<vector<int>> g(n);
   for (int i = 0; i < n; ++i) {
      cin >> u[i];
      --u[i];
   }
   vector<int> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
      g[u[i]].push_back(s[i]);
   }
   vector<int> ans(n + 1);
   for (int i = 0; i < n; ++i) {
      sort(all(g[i]), greater{});
      int sz = g[i].size();
      vector<int> pre(sz + 1);
      for (int j = 1; j <= sz; ++j) {
         pre[j] = pre[j - 1] + g[i][j - 1];
      }
      for (int t = 1; t <= sz; ++t) {
         for (int k = t; k <= sz; k += t) {
            ans[t] += pre[k] - pre[k - t];
         } 
      }
   }
   for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " \n"[i == n];
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