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

int dp[N];

void test(){
   int n;
   cin >> n;
   cout << dp[n] << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   dp[0] = 1;
   for (int i = 1; i < N; ++i) {
      for (int j : {1, 2, 4, 6}) {
         if (i - j >= 0) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
         }
      }
   }


   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}