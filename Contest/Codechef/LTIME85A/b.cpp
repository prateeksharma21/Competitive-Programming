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
using ld = long double;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   cout << setprecision(14) << fixed;
   vector<array<int,3>> A(n);
   f(i,0,n){
      cin >> A[i][0] >> A[i][1] >> A[i][2];
   }
   ld ff = 0, ss = 0;
   f(i,0,n){
      int g = A[i][0];
      int x = A[i][1], y = A[i][2];
      ld d = (x*y);
      d /= (x+y);
      ff += (d*g)/x;
      ss += (d*g)/y;
   }
   cout << ff << ' ' << ss << '\n';
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
