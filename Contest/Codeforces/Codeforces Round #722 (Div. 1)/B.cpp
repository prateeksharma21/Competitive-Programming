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
const int MOD = 998244353, N = 1e6 + 10; 

int dp[N];
int f[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;

   for (int i = 1; i < N; ++i) {
      for (int j = i; j < N; j += i) {
         f[j]++;
         if (f[j] >= MOD) f[j] -= MOD;
      }
   }

   dp[1] = 1;
   int sm = 1;
   for (int i = 2; i <= n; ++i) {
      dp[i] = f[i] + sm;
      if (dp[i] >= MOD) dp[i] -= MOD;
      sm += dp[i];
      if (sm >= MOD) sm -= MOD;
   } 
   cout << dp[n] << '\n';
   return 0;
}