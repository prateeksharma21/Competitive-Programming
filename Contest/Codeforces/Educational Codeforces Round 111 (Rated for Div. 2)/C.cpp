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
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      int lst = n;
      for (int j = i; j < min(n, i + 7); ++j) {
         for (int k = j + 1; k < min(n, i + 7); ++k) {
            for (int l = k + 1; l < min(n, i + 7); ++l) {
               if (abs(a[j] - a[l]) == abs(a[j] - a[k]) + abs(a[k] - a[l])) {
                  lst = min(lst, l);
               }
            }
         }
      }
      ans += lst - i;
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