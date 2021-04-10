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

void Solve() {
   int n;
   cin >> n;
   vector<string> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int ans = 0;
   for (int i = 1; i < n; ++i) {
      if (a[i].length() > a[i - 1].length()) continue;
      int c = -1;
      for (int j = 0; j < a[i].length(); ++j) {
         if (a[i][j] > a[i - 1][j]) {
            c = 1;
            break;
         }
         if (a[i][j] < a[i - 1][j]) {
            c = 0;
            break;
         }
      }
      if (c == 1) {
         while (a[i].length() < a[i - 1].length()) {
            a[i] += "0";
            ++ans;
         }
      } else if (c == 0) {
         while (a[i].length() < a[i - 1].length()) {
            a[i] += "0";
            ++ans;
         }
         a[i] += "0";
         ++ans;
      } else {
         int cur = a[i].length();
         string prv = a[i];
         a[i] = a[i - 1];
         int j = a[i].length();
         ans += j - cur;
         --j;
         while (j >= 0 and a[i][j] == '9') --j;
         if (j >= cur) {
            a[i][j]++;
            for (int k = j + 1; k < a[i].length(); ++k) {
               a[i][k] = '0';
            }
         } else {
            a[i] = prv;
            while (a[i].length() < a[i - 1].length()) a[i] += "0";
            a[i] += "0";
            ++ans;
         }
      }
   }
   debug(a);
   cout << ans << '\n';
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