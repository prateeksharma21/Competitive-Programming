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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (int &i : a) cin >> i;
   int cur = 0;
   map<int, int> cnt;
   auto add = [&](int x) {
      if (cnt[x] == 0) ++cur;
      ++cnt[x];
   };
   auto remove = [&](int x) {
      if (cnt[x] == 1) --cur;
      --cnt[x];
   };
   for (int i = 0; i < k; ++i) add(a[i]);
   int ans = cur;
   for (int i = k; i < n; ++i) {
      remove(a[i - k]);
      add(a[i]);
      ans = max(ans, cur);
   }
   cout << ans;
   return 0;
}