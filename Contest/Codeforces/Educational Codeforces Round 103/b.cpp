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
   int n, k;
   cin >> n >> k;
   vector<int> p(n);
   for (int i = 0; i < n; ++i) {
      cin >> p[i];
   }
   int sm = p[0];
   int ans = 0;
   for (int i = 1; i < n; ++i) {
      int val = p[i] * 100;
      int oth = sm * k;
      if (val > oth) {
         int req = val - oth;
         int inc = (req + k - 1) / k;
         ans += inc;
         sm += inc;
      }
      sm += p[i];
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