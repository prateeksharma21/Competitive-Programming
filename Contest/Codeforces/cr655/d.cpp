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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> a(n);
   int sm[2] = {0,0};
   f(i,0,n){
      cin >> a[i];
      sm[i%2] += a[i];
   }
   int cur[2] = {0,0};
   int ans = 0;
   f(i,0,n){
      // debug(sm[i%2]+cur[1-i%2]);
      ans = max(ans,sm[i%2]+cur[1-i%2]);
      cur[i%2] += a[i];
      sm[i%2] -= a[i];
      // debug(ans);
   }
   cout << ans << '\n';
   return 0;
}