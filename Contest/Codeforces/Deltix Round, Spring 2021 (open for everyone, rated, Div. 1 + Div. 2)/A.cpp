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
   int n, m;
   cin >> n >> m;
   string s;
   cin >> s;
   for (int i = 0; i < min(n + 2, m); ++i) {
      string t = s;
      for (int j = 0; j < n; ++j) {
         if (s[j] == '1') continue;
         if (j == 0) {
            if (s[j + 1] == '1') {
               t[j] = '1';
            }
         } else if (j == n - 1) {
            if (s[j - 1] == '1') {
               t[j] = '1';
            }
         } else {
            int c = (s[j - 1] == '1') + (s[j + 1] == '1');
            if (c == 1) {
               t[j] = '1';
            }
         }
      }      
      s.swap(t);
   }
   cout << s << '\n';
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