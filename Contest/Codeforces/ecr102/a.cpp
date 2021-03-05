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
   int n, d;
   cin >> n >> d;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) cin >> a[i];
   sort(all(a));
   for (int i = 2; i < n; ++i) {
      a[i] = min(a[i], a[0] + a[1]);
   }
   sort(all(a));
   if (a.back() <= d) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
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