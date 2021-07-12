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
   int n = s.length();
   vector<int> dp(n);
   vector<int> lst(n);
   dp[n - 1] = 1;
   int cnt = (s[n - 1] == '?');
   lst[n - 1] = n - 1;
   int ans = 0;
   for (int i = n - 2; i >= 0; --i) {
      if (s[i] == '?') {
         lst[i] = lst[i + 1];
         cnt++;
      } else {
         if (s[i] == s[i + 1]) {
            lst[i] = i;
         } else {
            if (s[i + 1] == '?') {
               if (cnt % 2 == 0) {
                  if (i + cnt == n - 1) {
                     lst[i] = n - 1;
                  } else {
                     if (s[i + cnt + 1] == s[i]) {
                        lst[i] = i + cnt;
                     } else {
                        lst[i] = lst[i + 1];
                     }
                  }
               } else {
                  if (i + cnt == n - 1) {
                     lst[i] = n - 1;
                  } else {
                     if (s[i + cnt + 1] != s[i]) {
                        lst[i] = i + cnt;
                     } else {
                        lst[i] = lst[i + 1];
                     }
                  }
               }
            } else {  
               lst[i] = lst[i + 1];
            }
         }
         cnt = 0;

      }
      ans += (lst[i] - i + 1);
   }
   cout << ans + 1 << '\n';
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