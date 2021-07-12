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
   int a[4];
   int b[4];
   for (int i = 0; i < 4; ++i) {
      cin >> a[i];
      b[i] = a[i];
   }
   sort(a, a + 4);
   sort(b, b + 2);
   sort(b + 2, b + 4);
   if (b[1] == a[2] and b[3] == a[3]) {
      cout << "YES\n";
   } else if (b[1] == a[3] and b[3] == a[2]) {
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