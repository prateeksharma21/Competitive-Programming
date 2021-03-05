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

void test(){
   int n, c;
   cin >> n >> c;
   vector<int> a(n);
   int gc = 0;
   for (int &i : a) {
      cin >> i;
      gc = gcd(gc, i);
   }

   // suppose m == 1:
   if (gc != 1) {
      cout << 1 << '\n' << gc << '\n';
      return;
   }

   for (int i = 2; i <= c; ++i) {
      vector<int> rem;
      int gc = 0;
      for (int j : a) {
         if (j % i != 0) {
            gc = gcd(gc, j);
         }
      }
      if (gc != 1) {
         cout << 2 << '\n' << i << ' ' << gc << '\n';
         return;
      }
   }
   assert(false);
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}