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
   if (s.length() <= 3) {
      cout << "Error\n";
      return;
   }
   int n = s.length();
   int x = (s[0] == '<' and s[1] == '/' and s[n - 1] == '>');
   for (int i = 2; i < n - 1; ++i) {
      x &= (isdigit(s[i]) or (s[i] >= 'a' and s[i] <= 'z'));
   }
   cout << (x ? "Success" : "Error") << '\n';
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