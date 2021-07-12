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
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> cnt(n + m + 1);
   for (int i = 0; i < k; ++i) {
      int l;
      cin >> l;
      cnt[l]++;
   }
   int res = 0;
   vector<int> val;
   for (int i = 1; i <= n; ++i) {
      res += cnt[i] > 1;
      if (cnt[i] > 1) val.push_back(i);
   }
   cout << res << ' ';
   for (int i : val) {
      cout << i << ' ';
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