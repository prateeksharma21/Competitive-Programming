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
   int a, b, k;
   cin >> a >> b >> k;
   int n = a + b;
   if (n == b) {
      if (k == 0) {
         cout << "Yes\n";
         cout << string(n, '1') << '\n' << string(n, '1') << '\n';
      } else {
         cout << "No\n";
      }
      return 0;
   }
   if (b == 1) {
      if (k == 0) {
         cout << "Yes\n";
         cout << "1" + string(n - 1, '0') << '\n' <<  "1" + string(n - 1, '0') << '\n';
      } else {
         cout << "No\n";
      }
      return 0;
   }
   if (k == n or k == n - 1) {
      cout << "No\n";
      return 0;
   }
   string x = "";
   for (int i = 0; i < b; ++i) x += '1';
   for (int i = 0; i < a; ++i) x += '0';

   string y = x;
   if (k <= a) {
      swap(y[b - 1], y[b - 1 + k]);
   } else {
      int ex = k - a;
      assert(b - 1 - ex > 0);
      swap(y[b - 1 - ex], y[n - 1]);
   }

   cout << "Yes\n";
   cout << x << '\n' << y << '\n';   
   return 0;
}