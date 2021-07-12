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
   int h, w;
   for (int i = 1; i < n; ++i) {
      cout << "?" << endl;
      for (int j = 0; j < n; ++j) {
         for (int k = 0; k < n; ++k) {
            if (j == i) cout << 0;
            else cout << 1;
         }
         cout << endl;
      }
      int x;
      cin >> x;
      if (x == 1) {
         h = i;
         break;
      }
   }
   for (int i = 1; i < n; ++i) {
      cout << "?" << endl;
      for (int j = 0; j < n; ++j) {
         for (int k = 0; k < n; ++k) {
            if (k == i) cout << 0;
            else cout << 1;
         }
         cout << endl;
      }
      int x;
      cin >> x;
      if (x == 1) {
         w = i;
         break;
      }
   }
   cout << "!" << endl;
   cout << h << ' ' << w << endl;
   cin >> h;
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