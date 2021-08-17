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
   vector<int> pos[2][26];
   for (int i = 0; i < n; ++i) {
      pos[i & 1][s[i] - 'a'].push_back(i);
   }
   {
      int cur = 0;
      int idx = -1;
      int v = 1;
      for (int i = 0; i < m; ++i) {
         auto k = upper_bound(all(pos[cur][t[i] - 'a']), idx);
         if (k == pos[cur][t[i] - 'a'].end()) {
            v = 0;
            break;
         }
         cur ^= 1;
         idx = *k;
      }
      if (v and (n - idx) & 1) {
         cout << "YES\n";
         return;
      }
   }
   {
      int cur = 1;
      int idx = -1;
      int v = 1;
      for (int i = 0; i < m; ++i) {
         auto k = upper_bound(all(pos[cur][t[i] - 'a']), idx);
         if (k == pos[cur][t[i] - 'a'].end()) {
            v = 0;
            break;
         }
         cur ^= 1;
         idx = *k;
      }
      if (v and (n - idx) & 1) {
         cout << "YES\n";
         return;
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