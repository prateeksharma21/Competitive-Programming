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
   int v = 1;
   for (int i = 1; i < 4; ++i) {
      int a = s[i - 1] - '0';
      int b = s[i] - '0';
      v &= ((a + 1) % 10 == b);
   }
   sort(all(s));
   if (s.front() == s.back() or v) {
      cout << "Weak";
   } else {
      cout << "Strong";
   }

   return 0;
}