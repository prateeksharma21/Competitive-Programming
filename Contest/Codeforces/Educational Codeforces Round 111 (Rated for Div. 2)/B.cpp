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
   int n, a, b;
   cin >> n >> a >> b;
   string s;
   cin >> s;
   if (b >= 0) {
      cout << a * n + b * n << '\n';
      return;
   }
   int ans = a * n;
   int len = 0;
   for (int i = 0, j = 0; i < n; i = j) {
      while (j < n and s[i] == s[j]) ++j;
      ++len;
   }
   ans += (len / 2 + 1) * b;
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