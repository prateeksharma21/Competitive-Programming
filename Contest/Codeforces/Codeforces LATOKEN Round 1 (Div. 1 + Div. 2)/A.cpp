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
   set<char> se[2];
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (int j = 0; j < m; ++j) {
         if (s[i][j] != '.') {
            se[(i + j) % 2].insert(s[i][j]);
         }
      }
   }
   if (se[0].size() == 2 or se[1].size() == 2) {
      cout << "NO\n";
      return;
   }
   char a, b;
   if (se[0].empty() and se[1].empty()) {
      a = 'R', b = 'W';
   } else if (se[0].empty()) {
      if (*se[1].begin() == 'R') {
         a = 'W';
         b = 'R';
      } else {
         a = 'R';
         b = 'W';
      }
   } else if (se[1].empty()) {
      if (*se[0].begin() != 'R') {
         a = 'W';
         b = 'R';
      } else {
         a = 'R';
         b = 'W';
      }
   } else {
      a = *se[0].begin();
      b = *se[1].begin();
      if (a == b) {
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
   vector<char> c = {a, b};
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cout << c[(i + j) % 2];
      }
      cout << '\n';
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