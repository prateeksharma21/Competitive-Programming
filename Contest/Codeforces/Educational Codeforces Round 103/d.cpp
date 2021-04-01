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
   int c = 0;
   int nxt[n + 1][2];
   int prv[n + 1][2];
   memset(nxt, 0, sizeof nxt);
   memset(prv, 0, sizeof prv);
   for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == 'L') {
         prv[i][0] += 1 + prv[i - 1][1];
         prv[i][1] = 0;
      } else {
         prv[i][0] = 0;
         prv[i][1] += 1 + prv[i - 1][0];
      }
   }
   for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'L') {
         nxt[i][0] += 1 + nxt[i + 1][1];
         nxt[i][1] = 0;
      } else {
         nxt[i][0] = 0;
         nxt[i][1] += 1 + nxt[i + 1][0];
      }
   }
   
   for (int i = 0; i < n + 1; ++i) {
      cout << prv[i][0] + nxt[i][1] + 1 << ' ';
   }
   cout << '\n';
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