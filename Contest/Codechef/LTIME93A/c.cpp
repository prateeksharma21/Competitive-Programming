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

void test0(){
   int n, q;
   cin >> n >> q;
   vector<int> apply(n + 3);
   for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      apply[l] += 1;
      apply[r + 1] -= 1;
   }
   vector<int> r(n + 1);
   for (int i = 1; i <= n; ++i) {
      apply[i] += apply[i - 1];
      if (apply[i]) r[i] = i;
      else r[i] = 1;
      cout << r[i] << ' ';
   }
   cout << '\n';
   return;
}

void test1() {
   int n, q;
   cin >> n >> q;
   vector<int> apply(n + 3);
   vector<int> res(n + 1, n);
   vector<int> fixed(n + 1);

   vector<array<int, 2>> Q;
   for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      Q.push_back({l, r});
   }

   sort(all(Q), [&](array<int, 2> a, array<int, 2>b){
      return a[1] - a[0] < b[1] - b[0];
   });

   for (auto [l, r] : Q) {
      set<int> req;
      for (int i = l; i <= r; ++i) {
         req.insert(i);
      }
      for (int i = l; i <= r; ++i) {
         if (fixed[i]) req.erase(i);
      }
      for (int i = l; i <= r; ++i) {
         if (fixed[i]) continue;
         auto lk = *prev(req.end());
         res[i] = lk;
         req.erase(lk);
         fixed[i] = 1;
      }
   }
   for (int i = 1; i <= n; ++i) {
      if(res[i] == 0) res[i] = n;
      cout << res[i] << ' ';
   }
   cout << '\n';
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1, p;
   cin >> tt >> p;
   for (int t = 1; t <= tt; ++t) {
      if (p == 0) {
         test0();
      } else {
         test1();
      }
   }
   return 0;
}