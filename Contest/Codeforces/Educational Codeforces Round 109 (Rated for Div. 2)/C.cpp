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
   int n, m;
   cin >> n >> m;
   vector<int> v(n);
   iota(all(v), 0LL);
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<char> dir(n);
   for (int i = 0; i < n; ++i) {
      cin >> dir[i];
   }
   sort(all(v), [&](int x, int y){
      return a[x] < a[y];
   });

   vector<array<int, 2>> L[2];
   vector<array<int, 2>> R[2];
   vector<int> ans(n, -1);
   for (int i : v) {
      if (dir[i] == 'R') {
         R[a[i] & 1].push_back({a[i], i});
         continue;
      }
      int p = a[i] & 1;
      if (!R[p].empty()) {
         ans[i] = (a[i] - R[p].back()[0]) / 2;
         ans[R[p].back()[1]] = ans[i];
         R[p].pop_back();
      } else {
         L[p].push_back({a[i], i});
      }
   }
   for (int i = 0; i < 2; ++i) {
      while (R[i].size() > 1) {
         auto [v1, p1] = R[i].back();
         R[i].pop_back();
         auto [v2, p2] = R[i].back();
         R[i].pop_back();
         ans[p1] = m - v1 + abs(v1 - v2) / 2;
         ans[p2] = m - v1 + abs(v1 - v2) / 2;
      }
   }
   for (int i = 0; i < 2; ++i) {
      reverse(all(L[i]));
      while (L[i].size() > 1) {
         auto [v1, p1] = L[i].back();
         L[i].pop_back();
         auto [v2, p2] = L[i].back();
         L[i].pop_back();
         ans[p1] = v1 + abs(v1 - v2) / 2;
         ans[p2] = v1 + abs(v1 - v2) / 2;
      }
   }
   if (!R[0].empty() and !L[0].empty()) {
      auto [v1, p1] = L[0].back();
      auto [v2, p2] = R[0].back();
      int v = max(v1, m  - v2);
      int d = max(v1, m - v2) - min(v1, m - v2);
      int an = v + (m - d) / 2;
      ans[p1] = an;
      ans[p2] = an;
   }
   if (!R[1].empty() and !L[1].empty()) {
      auto [v1, p1] = L[1].back();
      auto [v2, p2] = R[1].back();
      int v = max(v1, m  - v2);
      int d = max(v1, m - v2) - min(v1, m - v2);
      int an = v + (m - d) / 2;
      ans[p1] = an;
      ans[p2] = an;
   }
   for (int i = 0; i < n; ++i) {
      cout << ans[i] << " \n"[i == n - 1];
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