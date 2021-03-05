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
   vector<int> c(n), a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> c[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> b[i];
   }
   vector<int> largest(n);
   for (int i = 1; i < n; ++i) {
      if (a[i] == b[i]) {
         largest[i] = c[i] - 1 + 2;
      } else {
         largest[i] = max(c[i] + 1 + abs(b[i] - a[i]), c[i] + 1 + largest[i - 1] - abs(b[i] - a[i]));
      }
   }
   cout << *max_element(all(largest)) << '\n';
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