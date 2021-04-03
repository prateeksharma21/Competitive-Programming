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
   string s;
   cin >> s;
   string t;
   cin >> t;
   int one = 0, zero = 0;
   for (char &i : s) {
      i -= '0';
   }
   vector<int> valid(n);
   for (int i = 0; i < n; ++i) {
      t[i] -= '0';
      one += s[i];
      zero += 1 - s[i];
      if (one == zero) valid[i] = 1;
   }
   int f = 0;
   for (int i = n - 1; i >= 0; --i) {
      int v = s[i] + f;
      v %= 2;
      if (v != t[i]) {
         if (valid[i]) {
            f ^= 1;
         } else {
            cout << "NO\n";
            return;
         }
      }
   }
   cout << "YES\n";
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