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
const int MOD = 1e9+7, N = 1e7 + 10;

int ans[N];
int sum[N];

void test(){
   int x;
   cin >> x;
   cout << ans[x] << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(ans, -1, sizeof ans);
   int tt = 1;
   for (int i = 1; i < N; ++i) {
      for (int j = i; j < N; j += i) {
         sum[j] += i;
      }
      if (sum[i] < N and ans[sum[i]] == -1) {
         ans[sum[i]] = i;
      }
   }
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}