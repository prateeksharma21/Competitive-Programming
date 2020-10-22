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
   int a,b,x,y,n;
   cin >> a >> b >> x >> y >> n;

   auto solve = [&](int a,int b,int x,int y,int n){
      int d = a-x;
      int mn = min(n,d);
      a -= mn;
      n -= mn;
      d = b-y;
      mn = min(n,d);
      b -= mn;
      return a*b;
   };

   cout << min(solve(a,b,x,y,n),solve(b,a,y,x,n)) << '\n';
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
