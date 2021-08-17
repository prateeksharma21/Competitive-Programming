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
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   // n + 1 -> 1 -> 2 .. n:
   if (a[1]) {
      cout << n + 1 << ' ';
      for (int i = 1; i <= n; ++i) {
         cout << i << ' ';
      }
      cout << '\n';
      return;
   }
   // 1 -> 2 -> 3 .. n -> n + 1
   if (!a[n]) {
      for (int i = 1; i <= n; ++i) {
         cout << i << ' ';
      }
      cout << n + 1 << ' ';
      cout << '\n';
      return;  
   }
   for (int i = 1; i + 1 <= n; ++i) {
      if (a[i] == 0 and a[i + 1] == 1) {
         for (int j = 1; j <= i; ++j) cout << j << ' ';
         cout << n + 1 << ' ';
         for (int j = i + 1; j <= n; ++j) cout << j << ' ';
         cout << '\n';
         return;
      }
   }
   cout << -1 << '\n';
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