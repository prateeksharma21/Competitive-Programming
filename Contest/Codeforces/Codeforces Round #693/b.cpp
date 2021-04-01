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
   int sm = 0;
   vector<int> a(n);
   for (int i = 0, x; i < n; ++i) {
      cin >> x;
      a[i] = x;
      sm += x;
   }
   if (sm & 1) {
      cout << "NO\n";
      return;
   }
   vector<vector<int>> dp(n, vector<int>(n * 2 + 1, -1));
   
   function<bool(int, int)> dfs = [&](int i, int sm) {
      if (sm < 0) return false;
      if (i == -1) {
         return sm == 0;
      }
      int &ans = dp[i][sm];
      if (ans != -1) return bool(ans);
      ans = 0;
      ans |= dfs(i - 1, sm);
      ans |= dfs(i - 1, sm - a[i]);
      return bool(ans);
   };

   if (dfs(n - 1, sm / 2)) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
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