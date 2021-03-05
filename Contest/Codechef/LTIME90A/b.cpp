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
   int res = 0;

   vector <pair<int, int>> R;
   for (int i = 1; i <= n; ++i) {
      int c = 0;
      for (int j = i; j <= n; ++j) {
         int u = i * (j + 1);
         int d = (i + 1) * j;
         int gc = gcd(u, d);
         u /= gc;
         d /= gc;
         if (u + 1== d ) {
            R.push_back({i,j});
            ++c;
         }
      }
      debug(c);
   }


   for (int i = 1; i < n; ++i) {
      int l = i + 1, r = n;
      int ans = l;
      while (l <= r) {
         int m = (l + r) / 2;
         int u = i * (m + 1);
         int d = (i + 1) * m;
         int g = gcd(u, d);
         u /= g;
         d /= g;
         if (u + 1 == d) {
            l = m + 1;
            ans = m;
         } else {
            r = m - 1;
         }
      }
      res += (ans - i);
   }
   debug(R);
   debug(R.size());
   cout << res << '\n';
   return 0;
} 