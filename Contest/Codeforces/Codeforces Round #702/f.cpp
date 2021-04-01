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
   int mx = 0;
   map<int, int> cnt;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
      mx = max(mx, cnt[a[i]]);
   }
   vector<int> freq;
   for (auto e : cnt) {
      freq.push_back(e.second);
   }
   sort(all(freq));
   int p = 0;
   int ans = n;
   for (int i = 1; i <= mx; ++i) {
      int K = 0;
      while (p < freq.size() and freq[p] == i) {
         ++p;
         ++K;
      }
      int rem = (int)freq.size() - p;
      ans = min(ans, n - (K + rem) * i);
   }
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