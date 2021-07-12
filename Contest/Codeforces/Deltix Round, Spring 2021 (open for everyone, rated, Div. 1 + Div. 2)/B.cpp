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
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   cout << (n / 2) * 6 << '\n';
   for (int i = 1; i <= n; i += 2) {
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
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