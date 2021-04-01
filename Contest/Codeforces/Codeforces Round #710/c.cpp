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
   string s, t;
   cin >> s >> t;
   int n = s.length(), m = t.length();

   map<string, bool> A, B;

   for (int i = 0; i < n; ++i) {
      string ns = "";
      for (int j = i; j < n; ++j) {
         ns += s[j];
         A[ns] = true;
      }
   }

   for (int i = 0; i < m; ++i) {
      string nt = "";
      for (int j = i; j < m; ++j) {
         nt += t[j];
         B[nt] = true;
      }
   }

   int mn = n + m;
   debug(n, m);

   for (auto &e : A) {
      if (B[e.first]) {
         mn = min(mn, n + m - 2 * int(e.first.length()));
      }
   }

   cout << mn << '\n';
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