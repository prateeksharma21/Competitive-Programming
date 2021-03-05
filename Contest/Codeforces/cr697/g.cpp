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
const int MOD = 1e9+7, N = 2e5 + 10;

int dp[N];
int cnt[N];
vector<int> f[N];

void test(){
   int n;
   cin >> n;
   memset(cnt, 0, sizeof cnt);
   for (int i = 0, x; i < n; ++i) {
      cin >> x;
      cnt[x]++;
   }
   int ans = 0;
   for (int i = 1; i <= N; ++i) {
      dp[i] = cnt[i];
      int v = 0;
      for (int j : f[i]) {
         if (j == i) continue;
         v = max(v, dp[j]);
      }      
      dp[i] += v;
      ans = max(ans, dp[i]);
   }
   cout << n - ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   for (int i = 1; i < N; ++i) {
      for (int j = i; j < N; j += i) {
         f[j].push_back(i);
      }
   }
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}