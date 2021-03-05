#ifdef Prateek
  #include "\Prateek.h"
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
   vector<int> A(n);
   for(int &i : A) {
      cin >> i;
   }
   sort(all(A));
   vector<vector<int>> dp(n, vector<int>(411,-1));

   function<int(int,int)> dfs = [&](int i, int tm) {
      if(i == n) return 0LL;
      int &ans = dp[i][tm];
      if(ans != -1) return ans;
      ans = 1e9;
      for(int j = tm; j <= 400; ++j) {
         ans = min(ans, abs(A[i]-j) + dfs(i+1, j+1));
      }
      return ans;
   };

   cout << dfs(0, 1) << '\n';
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