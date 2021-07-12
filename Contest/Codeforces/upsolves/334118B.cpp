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
   vector<int> cnt(26);
   for (char i : s) cnt[i - 'a'] = 1;
   int ans = 0;
   for (int i = 0; i < 26; ++i) {
      ans += (!cnt[i]) * (i + 1);
   }
   string res = to_string(ans);
   if (ans % 3 == 0 or count(all(res), '3') != 0) {
      cout << "yummy\n";
   } else {
      cout << "not yummy\n";
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