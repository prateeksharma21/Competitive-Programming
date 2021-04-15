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
   vector<int> a(n + 2);
   int sum = 0;
   for (int i = 0; i < n + 2; ++i) {
      cin >> a[i];
      sum += a[i];      
   }
   sort(all(a));
   // chech if last is the sum:
   for (int i = 0; i < n + 1; ++i) {
      if (sum - a[n + 1] - a[i] == a[n + 1]) {
         for (int j = 0; j < n + 1; ++j) {
            if (j == i) continue;
            cout << a[j] << ' ';
         } 
         cout << '\n';
         return;
      }
   }

   // check if the second last is sum:
   sum -= a[n + 1] + a[n];
   if (sum == a[n]) {
      for (int i = 0; i < n; ++i) {
         cout << a[i] << ' ';
      }
      cout << '\n';
   } else {
      cout << -1 << '\n';
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