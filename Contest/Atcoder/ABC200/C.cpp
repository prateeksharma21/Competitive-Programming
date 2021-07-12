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
   int n;
   cin >> n;
   map<int, int> cnt;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x % 200]++;
   }
   int ans = 0;
   for (auto [_, v] : cnt) {
      ans += v * (v - 1) / 2;
   }
   cout << ans << '\n';
   return 0;
}