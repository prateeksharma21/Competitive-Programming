#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i : a) {
      cin >> i;
   }
   vector<vector<int>> dp(n, vector<int>(2, -1));
   vector<int> lst(n + 1);
   int cur_mx = 0;
   int ans = n;
   for (int i = n - 1; i >= 0; --i) {
      if (lst[a[i]]) {
         dp[i][0] = lst[a[i]] + 1;
         ans = min(ans, n - dp[i][0]);
      }
      dp[i][1] = cur_mx + 1;
      lst[a[i]] = max(lst[a[i]], dp[i][1]);
      cur_mx = max(cur_mx, dp[i][0]);
   }
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}