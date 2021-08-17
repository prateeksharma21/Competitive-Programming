#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int h, w, n;
   cin >> h >> w >> n;
   vector<int> x(n), y(n);
   for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
   }
   vector<int> a = x;
   sort(all(a));
   map<int, int> sX, sY;
   int cur = 0;
   int prv = 0;
   for (int i = 0; i < n; ++i) {
      if (a[i] == prv) continue;
      cur += a[i] - prv - 1;
      sX[a[i]] = cur;
      prv = a[i];
   }
   a = y;
   sort(all(a));
   cur = 0, prv = 0;
   for (int i = 0; i < n; ++i) {
      if (a[i] == prv) continue;
      cur += a[i] - prv - 1;
      sY[a[i]] = cur;
      prv = a[i];
   }
   for (int i = 0; i < n; ++i) {
      cout << x[i] - sX[x[i]] << ' ' << y[i] - sY[y[i]] << '\n';
   }
   return 0;
}