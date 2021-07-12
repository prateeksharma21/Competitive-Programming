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
   int n;
   cin >> n;
   vector<int> r;
   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      int mx = *max_element(all(s)) - '0';
      r.push_back(mx);
   }
   sort(all(r), greater<int>());
   int ans = 0;
   int d;
   cin >> d;
   for (int i = 0; i < d; ++i) {
      ans += r[i];
   }
   cout << ans << '\n';
   return 0;
}