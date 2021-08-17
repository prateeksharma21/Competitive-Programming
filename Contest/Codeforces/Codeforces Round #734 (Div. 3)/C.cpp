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

int solve(vector<string> s, char c) {
   int n = s.size();
   vector<int> pos, neg;
   for (int i = 0; i < n; ++i) {
      int v = 0;
      for (char k : s[i]) {
         v += (k == c);
         v -= (k != c);
      }
      // debug(v, s[i]);
      if (v > 0) pos.push_back(v);
      else neg.push_back(v);
   }
   // debug(pos, neg);

   int res = accumulate(all(pos), 0LL);
   sort(all(neg), greater{});
   int ans = pos.size();
   for (int i = 0; i < neg.size(); ++i) {
      res += neg[i];
      if (res > 0) {
         ans = max(ans, (int)pos.size() + i + 1);
      }
   }
   return ans;
}

void test(){
   int n;
   cin >> n;
   vector<string> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   int ans = 0;
   for (char c = 'a'; c <= 'e'; ++c) {
      ans = max(ans, solve(s, c));
   }
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