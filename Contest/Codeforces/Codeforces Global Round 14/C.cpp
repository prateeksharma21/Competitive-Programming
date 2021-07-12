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
   int n, m, x;
   cin >> n >> m >> x;
   vector<array<int,2>> h(n);
   int sum = 0;
   set<array<int, 2>> s;
   for (int i = 0; i < n; ++i) {
      cin >> h[i][0];
      h[i][1] = i;
      sum += h[i][0];
   }
   for (int i = 0; i < m; ++i) {
      s.insert({0, i});
   }
   cout << "YES\n";
   sort(all(h));
   vector<int> res(n);
   for (int i = 0; i < n; ++i) {
      auto k = *s.begin();
      s.erase(s.begin());
      res[h[i][1]] = k[1] + 1;
      k[0] += h[i][0];
      s.insert(k);
   }
   for (int i : res) {
      cout << i << ' ';
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