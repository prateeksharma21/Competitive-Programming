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

void solve(string &s, int n) {
   if (n & 1) {
      int cnt = count(all(s), '0');
      if (s[n / 2] == '0' and cnt > 1) {
         cout << "ALICE\n";
      } else {
         cout << "BOB\n";
      }
      return;
   }
   cout << "BOB\n";
}

void test(){
   int n;
   string s;
   cin >> n >> s;
   string t = s;
   reverse(all(t));
   if (s == t) {
      solve(s, n);
      return;
   }
   int uneq = 0, eq = 0;
   int l = 0, r = n - 1;
   while (l < r) {
      uneq += (s[l] != s[r]);
      eq += (s[l] == s[r] and s[l] == '0'); 
      ++l;
      --r;
   }
   if (eq == 0) {
      if (n & 1 and uneq == 1 and s[n / 2] == '0') {
         cout << "DRAW\n";
      } else {
         cout << "ALICE\n";
      }
      return;
   }
   cout << "ALICE\n";
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