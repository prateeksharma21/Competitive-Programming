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
   int m,d,w;
   cin >> m >> d >> w;
   if(d == 1){
      m = min(m,d);
      cout << m*(m-1)/2 << '\n';
      return;
   }
   d--;
   int lc = lcm(w,d);
   int mul = lc/d;
   debug(mul);
   int kk = min(m,d+1);
   int v = (kk-1)/mul;
   if(v == 0){
      cout << "0\n";
      return;
   }
   int ans = v*kk-(v*(v+1)/2)*mul;
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
