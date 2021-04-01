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
   int n,x;
   cin >> n >> x;
   vector<int> a(n);
   f(i,0,n) cin >> a[i];
   sort(all(a));
   reverse(all(a));
   int ans = 0;
   int mn = 1e18, v = 0;
   f(i,0,n){
      mn = min(mn,a[i]);
      v++;
      if(v*mn >= x){
         ans++;
         mn = 1e18;
         v = 0;
      }
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
