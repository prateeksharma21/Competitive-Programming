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
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   if (count(all(s), '*') <= 2) {
      cout << count(all(s), '*') << '\n';
      return;
   } 

   vector<int> pos;
   for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
         pos.push_back(i);
      }
   }

   int sz = pos.size();

   int ans = 0;
   int prv = 0;
   for (int i = 1; i < sz; ++i) {
      if (pos[i] - pos[prv] > k) {
         ++ans;
         prv = i - 1;
      }
   }

   if (pos.back() - pos[prv] > k) ++ans;

   cout << ans + 2 << '\n';
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