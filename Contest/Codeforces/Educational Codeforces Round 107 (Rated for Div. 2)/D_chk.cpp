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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   for (int k = 2; k <= 26; ++k) {
      string s = "";
      for (int i = 0; i < k; ++i) {
         s += 'a' + i;
      }
      vector<string> a;
      for (int i = 0; i < k; ++i) {
         for (char c : s) {
            string T = "";
            T += i + 'a';
            T += c;
            a.push_back(T);
         }
         s = s.substr(1) + s[0];
      }
      int sz = k * k;
      assert(sz == a.size());
      string res = "";
      vector<int> done(sz);

      function<void(int)> dfs = [&](int u) {
         done[u] = 1;
         if (res.empty()) res += a[u];
         else res += a[u][1];
         for (int i = 0; i < sz; ++i) {
            if (!done[i] and a[i][0] == a[u][1]) {
               dfs(i);
            }
         }
      };

      dfs(0);

      int cost = 0;
      for (int i = 0; i + 1 < sz; ++i) {
         for (int j = i + 1; j + 1 < sz; ++j) {
            if (res[i] == res[j] and res[i + 1] == res[j + 1]) {
               ++cost;
            }
         }
      }

      assert(res.front() != res.back());

      // debug(res);
      assert(cost == 0 and res.length() == sz + 1);

   }
   return 0;
}