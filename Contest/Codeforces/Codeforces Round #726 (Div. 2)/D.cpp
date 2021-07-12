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
   int n;
   cin >> n;
   if (n & 1) {
      cout << "Bob\n";
      return;
   }
   if ((n & (n - 1)) == 0) {
      int c = 0;
      while (n) {
         ++c;
         n /= 2;
      }
      if (c & 1) {
         cout << "Alice\n";
      } else {
         cout << "Bob\n";
      }
   } else {
      cout << "Alice\n";
   }
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