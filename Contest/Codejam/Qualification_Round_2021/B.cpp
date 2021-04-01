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

int x, y;

int solve(string s) {
   int n = s.length();
   int ans = 0;
   for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == 'C' and s[i + 1] == 'J') {
         ans += x;
      }
      if (s[i] == 'J' and s[i + 1] == 'C') {
         ans += y;
      }
   }

   auto compute = [&](int i, int j) {
      int ans = 0;
      for (int k = i; k + 1 <= j; ++k) {
         if (s[k] == 'C' and s[k + 1] == 'J') {
            ans += x;
         }
         if (s[k] == 'J' and s[k + 1] == 'C') {
            ans += y;
         }     
      }
      return ans;
   };


   for (int i = 0, j = 0; i < n; i = j) {
      if (s[i] != '?') {
         ++j;
         continue;
      }

      while (s[i] == s[j]) ++j;
      

      for (int k = i; k < j; ++k) s[k] = 'J';
      int v1 = compute(i - 1, j);
      for (int k = i; k < j; k += 2) s[k] = 'C';
      int v2 = compute(i - 1, j);
      for (int k = i + 1; k < j; k += 2) s[k] = 'C';
      int v3 = compute(i - 1, j);
      for (int k = i; k < j; k += 2) s[k] = 'J';
      int v4 = compute(i - 1, j);

      ans += min({v1, v2, v3, v4});
   }

   return ans;
}

void Solve() {
   string s;
   cin >> x >> y >> s;
   s = "#" + s + "#";
   cout << solve(s) << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}