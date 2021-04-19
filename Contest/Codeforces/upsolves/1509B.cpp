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
   vector<int> t, m;
   for (int i = 0; i < n; ++i) {
      if (s[i] == 'T') {
         t.push_back(i);
      } else {
         m.push_back(i);
      }
   }
   if (t.size() != 2 * m.size()) {
      cout << "NO\n";
      return;
   }
   int sz = m.size();
   for (int i = 0; i < sz; ++i) {
      if (m[i] < t[i] or m[i] > t[i + sz]) {
         cout << "NO\n";
         return;
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