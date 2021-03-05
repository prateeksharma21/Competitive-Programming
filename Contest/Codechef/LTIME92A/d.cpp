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
   vector<array<int, 2>> A(n);
   int sm = 0;
   for (int i = 0; i < n; ++i) {
      cin >> A[i][0];
      A[i][1] = i;
      sm += A[i][0];
   }
   vector<int> G, L;
   sort(A.begin() + 1, A.end());
   vector<array<int, 3>> ops;
   set<array<int, 2>> s;
   for (int i = 1; i < n; ++i) {
      s.insert(A[i]);
   }
   for (int i = 1; i + 1 < n; ++i) {
      auto k = *s.begin();
      s.erase(s.begin());
      if (k[0] <= A[0][0]) {
         A[0][0] += k[0];
         ops.push_back({k[1], 0, k[0]});
      } else {
         int ex = k[0] - A[0][0];
         auto nx = *s.begin();
         s.erase(s.begin());
         nx[0] += ex;
         ops.push_back({k[1], nx[1], ex});
         k[0] -= ex;
         A[0][0] += k[0];
         ops.push_back({k[1], 0, k[0]});
         s.insert(nx);
      }
   }
   auto k = *s.begin();
   if (A[0][0] >= k[0]) {
      ops.push_back({k[1], 0, k[0]});
      cout << ops.size() << '\n';
      for (auto [a, b, c] : ops) {
         cout << a + 1 << ' ' << b + 1 << ' ' << c << '\n';
      }
   } else {
      cout << -1 << '\n';
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