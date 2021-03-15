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
   vector<string> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   for (int i = 0; i < m; i += 3) {
      for (int j = 0; j < n; ++j) {
         s[j][i] = 'X';
      }
   }
   for (int i = 3; i < m; i += 3) {
      if (n == 1) {
         s[0][i - 1] = s[0][i - 2] = 'X';
      } else {
         if (s[1][i - 1] == 'X' or s[1][i - 2] == 'X') {
            s[1][i - 1] = s[1][i - 2] = 'X';
         } else {
            s[0][i - 1] = s[0][i - 2] = 'X';
         }
      }
   }
   if (m % 3 == 0) {
      for (int j = 0; j < n; ++j) {
         if (s[j][m - 1] == 'X') {
            s[j][m - 2] = 'X';
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      cout << s[i] << '\n';
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