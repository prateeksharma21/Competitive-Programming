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
const int MOD = 1e9+7, N = 5e3 + 10; 

int n;
int dp[N];
int a[N];
int pre[N];

int get0(int l, int r) {
   int v = pre[r] - pre[l - 1];
   return (r - l + 1) - v;
}

int get1(int l, int r) {
   return pre[r] - pre[l - 1];
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for (int i = 1; i <= n; ++i) {
      vector<int> o, z;
      dp[i] = MOD;
      int v = 0;
      for (int j = i; j >= 1; --j) {
         if (a[j] == 1) {
            if (z.empty()) {
               o.push_back(j);
            } else {
               v += abs(j - z.back());
               z.pop_back();
            }
         } else {
            if (o.empty()) {
               z.push_back(j);
            } else {
               v += abs(j - o.back());
               o.pop_back();
            }
         }
         if (o.empty()) {
            dp[i] = min(dp[i], v + dp[j - 1]);
         }
      }
   }

   cout << dp[n] << '\n';
   return 0;
}