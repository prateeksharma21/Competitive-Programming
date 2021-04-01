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
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector <int> a(n);
   int sm = 0;
   int mx = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mx = max(mx, a[i]);
      sm += a[i];
   }
   int r = n-1;
   int req = r * ( (sm + r - 1) / r ) - sm;
   int Mx = (req + sm) / r;
   if (mx <= Mx) {
      cout << req << '\n';
   } else {
      cout << mx * r - sm << '\n';
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
