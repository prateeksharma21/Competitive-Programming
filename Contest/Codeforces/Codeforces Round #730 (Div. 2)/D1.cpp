#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
// #define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e4;

int dp[N][N];

void test(){
   int n, k;
   cin >> n >> k;
   cout << 0 << endl;
   int r;
   cin >> r;
   // assert(false);
   if (r == 1) return;
   for (int i = 1; i < n; ++i) {
      cout << (i ^ (i - 1)) << endl;
      cin >> r;
      if (r == 1) return;
   }
   assert(false);
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