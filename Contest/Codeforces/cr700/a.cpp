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

int a[N];

int query(int x) {
   if (a[x] == -1) {
      cout << "? " << x << endl;
      int y; cin >> y;
      a[x] = y;
   }
   return a[x];
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(a, -1, sizeof a);
   int n;
   cin >> n;
   a[0] = MOD, a[n + 1] = MOD;
   if (n <= 100) {
      for (int i = 1; i <= 100; ++i) {
         if (query(i) == 1) {
            cout << "! " << i << endl;
            return 0;
         }
      }
   }
   int l = 1, h = n;
   while (l <= h) {
      int m = (l + h) / 2;
      if (query(m) < query(m - 1) and query(m) < query(m + 1)) {
         cout << "! " << m << endl;
         return 0;
      }
      if (query(m) > query(m - 1) and query(m) < query(m + 1)) {
         h = m - 1;
      } else {
         l = m + 1;
      }
   }
   assert(false);
   return 0;
}