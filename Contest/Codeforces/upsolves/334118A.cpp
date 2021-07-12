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
   string s;
   cin >> s;
   int ans[2] = {0, 0}; 
   for (char c : s) {
      ans[(c - '0') & 1] += (c - '0');
   }
   cout << ans[0] << ' ' << ans[1] << '\n';
   return 0;
}