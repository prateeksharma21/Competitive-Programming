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
   auto get = [&](string s) -> int {
      int a = 0, b = 0;
      for (int i = 0; i < 10; ++i) {
         if (i % 2 == 0) {
            a += (s[i] - '0');
         } else {
            b += (s[i] - '0');
         }
         if (a > b) {
            int A = a;
            int B = b;
            int rem = 10 - i - 1;
            B += (rem + 1) / 2;
            if (A > B) {
               return i + 1;
            }
         } else {
            int A = a;
            int B = b;
            int rem = 10 - i - 1;
            A += rem / 2;
            if (B > A) {
               return i + 1;
            }
         }
      }
      return 10;
   };
   vector<int> pos;
   for (int i = 0; i < 10; ++i) {
      if (s[i] == '?') pos.push_back(i);
   }
   int sz = pos.size();
   int ans = 10;
   for (int mask = 0; mask < (1 << sz); ++mask) {
      string t = s;
      for (int i = 0; i < sz; ++i) {
         if (mask >> i & 1) {
            t[pos[i]] = '1';
         } else {
            t[pos[i]] = '0';
         }
      }
      ans = min(ans, get(t));
   }
   cout << ans << '\n';
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