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
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   for (int &i : a) {
      cin >> i;
   }

   vector<int> pre(n + 1);
   int mx = 0;
   for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] + a[i];
      mx = max(mx, pre[i + 1]);
   }

   vector<int> val(n);
   val[0] = pre[1];
   for (int i = 1; i < n; ++i) {
      val[i] = max(val[i - 1], pre[i + 1]);
   }

   vector<int> x(m);
   for (int i = 0; i < m; ++i) {
      cin >> x[i];
      auto k = lower_bound(all(val), x[i]) - begin(val);
      if (k != n) {
         cout << k << ' ';
         continue;
      }
      if (pre[n] <= 0) {
         cout << -1 << ' ';
         continue;
      }
      int one_turn = pre[n];
      int req_except_mx = x[i] - mx;
      int K = (req_except_mx + one_turn - 1) / one_turn;
      int done = K * one_turn;
      if (done == x[i]) {
         cout << K * n - 1 << '\n';
         continue;
      }
      int rem = x[i] - done;
      assert(rem <= mx);
      k = lower_bound(all(val), rem) - begin(val);
      cout << K * n + k << ' ';
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