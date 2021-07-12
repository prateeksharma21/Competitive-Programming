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

vector<string> res;

void test(){
   int n;
   cin >> n;
   string s;
   cin >> s;
   string res = "";
   map<string, bool> fnd;

   for (int i = 0; i < n; ++i) {
      string t = "";
      for (int j = i; j < min(i + 3, n); ++j) {
         t += s[j];
         fnd[t] = true;
      }
   }

   auto contain = [&](string t) {
      return fnd[t];
   };

   for (int i = 0; i < 26; ++i) {
      int fnd = count(all(s), i + 'a');
      if (fnd == 0) {
         cout << char(i + 'a') << '\n';
         return;
      }
   }

   for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
         string t = "";
         t += (i + 'a');
         t += (j + 'a');
         if (!contain(t)) {
            cout << t << '\n';
            return;
         }
      }
   }
   for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
         for (int k = 0; k < 26; ++k) {
            string t = "";
            t += (i + 'a');
            t += (j + 'a');
            t += (k + 'a');
            if (!contain(t)) {
               cout << t << '\n';
               return;
            }
         }
      }
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