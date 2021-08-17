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
   for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
         string base = s.substr(i, j - i + 1);
         int rem = m - (j - i + 1);
         int k = j - rem;
         if (k < 0) continue;
         string tmp = base;
         for (int x = 0; x < rem; x++) {
            tmp += s[j - 1 - x];
         }
         if (tmp == t) {
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