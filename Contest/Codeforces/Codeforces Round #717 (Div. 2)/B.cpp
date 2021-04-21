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
   vector<int> pre(n + 2), suff(n + 2);
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pre[i] = pre[i - 1] ^ a[i];
   }
   for (int i = n; i >= 1; --i) {
      suff[i] = suff[i + 1] ^ a[i];
   }
   for (int i = 1; i + 1 <= n; ++i) {
      if (pre[i] == suff[i + 1]) {
         cout << "YES\n";
         return;
      }
   }
   for (int i = 2; i <= n; ++i) {
      for (int j = i; j + 1 <= n; ++j) {
         if (pre[i - 1] == (pre[i - 1] ^ pre[j]) and pre[i - 1] == suff[j + 1]) {
            cout << "YES\n";
            return;
         }
      }
   }
   cout << "NO\n";
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