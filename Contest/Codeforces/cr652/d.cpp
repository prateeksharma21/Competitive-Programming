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
const int MOD = 1e9+7, N = 2e6 + 10;

int dp[N];

void test(){
   int n;
   cin >> n;
   cout << dp[n]*4 % MOD << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   dp[3] = dp[4] = 1;
   f(i,5,N) dp[i] = (dp[i-1]+2*dp[i-2]+(i%3 == 0)) % MOD;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
