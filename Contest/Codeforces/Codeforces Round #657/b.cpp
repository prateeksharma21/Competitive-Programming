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
const int MOD = 1e9+7, N = 5e5 + 10;


void test(){
   int l,r,m;
   cin >> l >> r >> m;
   f(a,l,r+1){
      int r1 = m%a;
      if(r1 <= r-l){
         if(m != r1){
            cout << a << ' ' << l+r1 << ' ' << l << '\n';
            return;
         }
      }
      int r2 = a-m%a;
      if(r2 <= r-l){
         cout << a << ' ' << l << ' ' << l+r2 << '\n';
         return;
      }
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
