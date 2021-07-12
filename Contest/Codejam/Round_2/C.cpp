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

map<vector<int>, int> cnt;

void Solve() {
   int n;
   cin >> n;
   vector<int> a(n), v(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int ans = 0;
   iota(all(v), 0LL);
   
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   vector<int> v
   do {
      vector<int> stk, b;
      for (int i = 0; i < n; ++i) {
         while (!stk.empty() and stk.back() < v[i]) {
            stk.pop_back();
         }
         stk.push_back(v[i]);
         b.push_back(stk.size());
      }
      ans += a == b;   
   } while (next_permutation(all(v)));


   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}