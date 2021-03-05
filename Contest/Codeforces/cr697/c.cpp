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
   map<pair<int, int>, int> cnt;
   vector<int> a(k);
   vector<int> cnta(n + 1);
   for (int i = 0; i < k; ++i) {
      cin >> a[i];
      cnta[a[i]]++;
   }
   vector<int> b(k);
   vector<int> cntb(m + 1);
   for (int i = 0; i < k; ++i) {
      cin >> b[i];
      cntb[b[i]]++;
      cnt[{a[i], b[i]}]++;
   }
   int ans = 0;
   for (int i = 0; i < k; ++i) {
      int rem = k - cnta[a[i]] - cntb[b[i]] + cnt[{a[i], b[i]}];
      ans += rem;
   }
   debug('a');
   cout << ans / 2 << '\n';
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