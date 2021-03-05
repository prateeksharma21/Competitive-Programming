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
   int n, m;
   cin >> n >> m;
   vector <int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<int> E(n);
   int mx = 0;
   vector<int> is_sort(n);
   for (int i = n - 1; i >= 0; --i) {
      if (a[i] == i + 1) {
         is_sort[i] = 1;
      } else {
         break;
      }
   }

   for (int i = 0; i < n - 1; ++i) {
      mx = max(mx, a[i]);
      if (mx == i + 1 and is_sort[i + 1]) {
         E[i] = 1;
      }
   }
   E[n - 1] = 1;
   debug(E);
   double ans = 0;
   double cur = 1;
   while (m--) {
      int x;
      double p;
      cin >> x >> p;
      --x;
      if (E[x]) {
         ans += cur * p;
         cur *= (1 - p);
      }
   }
   if (is_sort[0]) {
      ans += cur;
   }
   cout << setprecision(10) << fixed << ans << '\n';
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