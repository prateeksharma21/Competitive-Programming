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
   vector<int> cnt(401);
   for (int i = 0, x; i < n; ++i) {
      cin >> x;
      x += 200;
      cnt[x]++;
   }
   int ans = 0;
   for (int i = 0; i <= 400; ++i) {
      for (int j = i + 1; j <= 400; ++j) {
         ans += cnt[i] * cnt[j] * (j - i) * (j - i);
      }
   }
   cout << ans << '\n';
   return 0;
}