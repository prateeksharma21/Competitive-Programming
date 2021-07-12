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

// 1 2 2 2

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   int sum = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
   }
   vector<int> b(n);
   for (int i = 0; i < n; ++i) {
      b[i] = sum / n;
   }
   int rem = sum % n;
   for (int i = 0; i < rem; ++i) {
      b[i]++;
   }
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      sum -= b[i];
      ans += (n - i - 1) * b[i] - sum;
   }
   cout << ans << '\n';
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