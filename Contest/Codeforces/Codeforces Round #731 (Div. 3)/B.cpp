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
   string s;
   cin >> s;
   int n = s.length();
   set<int> se;
   for (int i = 0; i < n; ++i) {
      if (s[i] == 'a') se.insert(i);
   }
   if (se.empty()) {
      cout << "NO\n";
      return;
   }
   int l = *se.begin(), r = *se.begin();
   --l, ++r;
   for (int i = 1; i < n; ++i) {
      // debug(l, r);
      char c = i + 'a';
      if (l >= 0 and s[l] == c) {
         --l;
      } else if (r < n and s[r] == c) {
         ++r;
      } else {
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