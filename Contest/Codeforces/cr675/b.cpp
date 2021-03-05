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
   int n,m;
   cin >> n >> m;
   int a[n][m];
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   int ans = 0;
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         vector<int> K = {a[i][j], a[i][m-1-j], a[n-1-i][j], a[n-1-i][m-1-j]};
         sort(all(K));
         for(int i = 0; i < 4; ++i) {
            ans += abs(K[i]-K[1]);
         }  
      }
   }
   ans /= 4;
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
