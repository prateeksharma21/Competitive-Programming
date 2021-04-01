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
   int n, x;
   cin >> n >> x;
   vector<array<int, 2>> a(n);
   for (auto &[x, y] : a) {
      cin >> x;
      y = 1;
   }
   for (int i = 0; i < a.size(); ++i) {
      if (a[i][0] % x == 0) {
         a.push_back({a[i][0] / x, x * a[i][1]});
      } else {
         break;
      }
   }
   debug(a);
   int ans = 0;
   for (auto &[x, y] : a) {
      ans += x * y;
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