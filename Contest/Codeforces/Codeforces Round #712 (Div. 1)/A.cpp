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
   int c0 = count(all(s), '0');
   if (c0 & 1) {
      cout << "NO\n";
      return;
   }
   string a = "", b = "";
   int c1 = n - c0;
   c1 /= 2;
   int c = 0;
   for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
         if (c1) {
            a += '(';
            b += '(';
            --c1;
         } else {
            a += ')';
            b += ')';
         }
      } else {
         if (c) {
            a += '(';
            b += ')';
         } else {
            b += '(';
            a += ')';
         }
         c ^= 1;
      }
   }



   auto valid = [&](string s) {
      int v = 0;
      for (char c : s) {
         v += (c == '(' ? 1 : -1);
         if (v < 0) return false;
      }
      return v == 0;
   };

   if (valid(a) and valid(b)) {
      cout << "YES\n" << a << '\n' << b << '\n';
   } else {
      cout << "NO\n";
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