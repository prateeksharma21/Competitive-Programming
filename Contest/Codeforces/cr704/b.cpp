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
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   set<int> s;
   for (int i = 1; i <= n; ++i) s.insert(i);
   vector<vector<int>> R;
   for (int i = n - 1; i >= 0; --i) {
      vector<int> K;
      while (a[i] != *prev(s.end())) {
         s.erase(a[i]);
         K.push_back(a[i]);
         --i;
      }
      K.push_back(a[i]);
      reverse(all(K));
      s.erase(a[i]);
      R.push_back(K);
   }
   for (auto i : R) {
      for (auto j : i) {
         cout << j << ' ';
      }
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