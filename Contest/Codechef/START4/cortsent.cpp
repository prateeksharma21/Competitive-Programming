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

int capital(char c) {
   return c >= 'A' and c <= 'Z';
}

int small(char c) {
   return c >= 'a' and c <= 'z';
}

void test(){
   int n;
   cin >> n;
   vector<string> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   set<char> invalid;
   for (char c = 'A'; c <= 'M'; ++c) invalid.insert(c);
   for (char c = 'n'; c <= 'z'; ++c) invalid.insert(c);
   for (auto a : s) {
      int sm = 0, lg = 0;
      for (auto b : a) {
         sm |= small(b);
         lg |= capital(b);
         if (invalid.count(b)) {
            cout << "NO\n";
            return;
         }
      }
      if (sm & lg) {
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
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