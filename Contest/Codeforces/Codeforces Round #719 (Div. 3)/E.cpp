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
   string s;
   cin >> s;
   vector<int> p;
   for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
         p.push_back(i);
      }
   }
   int sz = p.size();
   vector<int> pre(sz + 2), suff(sz + 2);
   for (int i = 0; i < sz; ++i) {
      pre[i + 1] = pre[i] + p[i];
   }
   for (int i = sz; i ; --i) {
      suff[i] = suff[i + 1] + p[i - 1];
   }
   int ans = 1e18;
   for (int i = 1; i <= sz; ++i) {
      int prv = i - 1;
      int sum_prv = p[i - 1] * prv - pre[i - 1];
      sum_prv -= prv * (prv + 1) / 2;

      int nxt = sz - i;
      int sum_nxt = suff[i + 1] - p[i - 1] * nxt;
      sum_nxt -= nxt * (nxt + 1) / 2;
      ans = min(ans, sum_prv + sum_nxt);
   }
   ans = (ans == 1e18 ? 0 : ans);
   cout << ans << '\n';
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