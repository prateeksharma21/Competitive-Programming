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
   int a, b;
   cin >> a >> b;
   string s;
   cin >> s;
   int n = a + b;
   int l = 0, h = n - 1;
   while (l < h) {
      if (s[l] != '?') {
         if (s[h] == '?') {
            s[h] = s[l];
         } else {
            if (s[l] != s[h]) {
               cout << -1 << '\n';
               return;
            }
         }
      } else {
         if (s[h] != '?') {
            s[l] = s[h];
         }
      }
      ++l;
      --h;
   }
   int c0 = count(all(s), '0');
   int c1 = count(all(s), '1');
   debug(s);
   if (c0 > a or c1 > b) {
      cout << "-1\n";
      return;
   }
   debug("as");
   int r0 = a - c0, r1 = b - c1;
   debug(r0, r1);
   l = 0, h = n - 1;
   while (l < h) {
      if (s[l] == '?') {
         if (r0 > 1) {
            r0 -= 2;
            s[l] = s[h] = '0';
         } else if (r1 > 1) {
            r1 -= 2;
            s[l] = s[h] = '1';
         } else {
            cout << -1 << '\n';
            return;
         }
      }
      ++l;
      --h;
   }
   if (l == h and s[l] == '?') {
      if (r0) {
         s[l] = '0';
      } else if (r1) {
         s[l] = '1';
      } else {
         cout << -1 << '\n';
         return;
      }
   }
   cout << s << '\n';
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