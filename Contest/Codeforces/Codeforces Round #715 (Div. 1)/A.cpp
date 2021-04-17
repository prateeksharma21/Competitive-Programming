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

bool Try(string s, string t) {
   int n = s.length();
   int s0 = count(all(s), '0');
   int s1 = n - s0;
   bool swp = false;
   if (s1 < s0) {
      swp = true;
      for (int i = 0; i < n; ++i) {
         s[i] = 1 ^ (s[i] - '0') + '0';
         t[i] = 1 ^ (t[i] - '0') + '0';
      }
   } 

   int t0 = count(all(t), '0');
   int t1 = n - t0;

   if (t1 < t0) return false;

   string res;

   int i = 0, j = 0, rem = n;

   while (i < n and j < n) {
      if (s[i] == '0') {
         res += '0';
         ++i;
         continue;
      }
      if (t[j] == '0') {
         res += '0';
         ++j;
         continue;
      }
      if (rem) {
         --rem;
         res += '1';
         ++i, ++j;
      } else {
         res += "11";
         ++i, ++j;
      }
   }

   while (i < n) {
      res += s[i];
      ++i;
   }

   while (j < n) {
      res += t[j];
      ++j;
   }

   if (swp) {
      for (char &i : res) {
         i = 1 ^ (i - '0') + '0';
      }
   }

   cout << res << '\n';
   return true;
}

void test(){
   int n;
   cin >> n;
   string a[3];
   for (int i = 0; i < 3; ++i) {
      cin >> a[i];
   }
   if (Try(a[0], a[1])) return;
   if (Try(a[1], a[2])) return;
   if (Try(a[0], a[2])) return;
   while (true) {}
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