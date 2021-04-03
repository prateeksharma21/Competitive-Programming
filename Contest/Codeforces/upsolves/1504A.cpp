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
   int l = 0, r = n - 1;
   while (l <= r) {
      if (s[l] == s[r] and s[l] == 'a') {
         ++l, --r;
         continue;
      }
      cout << "YES\n";
      if (s[l] == s[r]) {
         cout << s.substr(0, l) + "a" + s.substr(l) << '\n';
      } else {
         cout << s.substr(0, l + 1) + "a" + s.substr(l + 1) << '\n';
      }
      return;
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