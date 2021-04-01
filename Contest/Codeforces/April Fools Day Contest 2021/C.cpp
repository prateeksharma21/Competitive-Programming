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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin >> s;
   int n = s.length();
   int ans = 0;
   if (n <= 2) {
      cout << "YES\n";
      return 0;
   }
   int a = s[0] - 'A', b = s[1] - 'A';
   for (int i = 2; i < n; ++i) {
      int c = (a + b) % 26;
      if (c != s[i] - 'A') {
         cout << "NO\n";
         return 0;
      }
      a = b;
      b = c;
   }
   cout << "YES\n";
   return 0;
}