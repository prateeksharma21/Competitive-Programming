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
   int n, m;
   cin >> n >> m;
   string s, t;
   cin >> s >> t;
   vector<int> fst(m), lst(m);
   for (int i = 0, j = 0; i < n and j < m; ++i) {
      if (s[i] == t[j]) {
         fst[j] = i;
         ++j;
      }
   }
   for (int i = n - 1, j = m - 1; i >= 0 and  j >= 0 ; --i) {
      if (s[i] == t[j]) {
         lst[j] = i;
         --j;
      }
   }
   int ans = 0;
   for (int i = 0; i + 1 < m; ++i) {
      ans = max(ans, lst[i + 1] - fst[i]);
   }
   for (int i = m - 1; i > 0; --i) {
      ans = max(ans, lst[i] - lst[i - 1]);
   }
   cout << ans << '\n';
   return 0;
}