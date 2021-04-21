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
const int MOD = 1e9+7, N = 2e5 + 10; 

int can[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> a(n);
   int sum = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
   }
   if (sum & 1) {
      cout << 0 << '\n';
      return 0;
   }
   can[0] = 1;
   sum /= 2;
   for (int i = 0; i < n; ++i) {
      for (int j = sum; j; --j) {
         if (j - a[i] >= 0) {
            can[j] |= can[j - a[i]];
         }
      }
   }
   if (!can[sum]) {
      cout << 0 << '\n';
      return 0;
   }
   for (int i = 0; i < 20; ++i) {
      int v = (1 << i);
      for (int j = 0; j < n; ++j) {
         if (a[j] % v == 0 and (a[j] / v) % 2 == 1) {
            cout << 1 << '\n' << j + 1 << '\n';
            return 0;
         }
      }
   }
   return 0;
}