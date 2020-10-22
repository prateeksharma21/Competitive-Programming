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
   int x1,y1,z1,x2,y2,z2;
   cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
   int ans = min(z1,y2)*2;
   z1 -= ans/2;
   y2 -= ans/2;
   int mn = min(z1,z2);
   z1 -= mn;
   z2 -= mn;
   mn = min(z2,x1);
   x1 -= mn;
   z2 -= mn;
   ans -= min(z2,y1)*2;
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
