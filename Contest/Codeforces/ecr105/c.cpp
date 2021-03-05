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

int solve(vector<int> &a, vector<int> &b) {
   int res = 0;
   // debug(a, b);
   set<int> fix;
   for (int i : a) {
      if (binary_search(all(b), i)) {
         fix.insert(i);
      }
   }
   // debug(fix);
   int n = a.size();
   if (!n) return res;
   int m = b.size();
   for (int i = 0; i < m; ++i) {
      // suppose we make a[0] to b[i];
      if (b[i] < a[0]) {
         continue;
      }
      int l = b[i], h = 1e18;
      int ans = 0;
      while (l <= h) {
         int m = (l + h) / 2;
         auto k = upper_bound(all(a), m) - a.begin();
         if (m - b[i] + 1 >= k) {
            ans = m;
            h = m - 1;
         } else {
            l = m + 1;
         }
      }
      while (!fix.empty() and *fix.begin() <= ans) {
         fix.erase(fix.begin());
      }
      int v = upper_bound(all(b), ans) - b.begin();
      res = max(res, (int)fix.size() + v - i);
   }
   return res;
}

void test(){
   int n, m;
   cin >> n >> m;
   vector<int> a(n), pos_a, neg_a;
   vector<int> b(m), pos_b, neg_b;
   for (int &i : a) {
      cin >> i;
      if (i > 0) {
         pos_a.push_back(i);
      } else {
         neg_a.push_back(-i);
      }
   }
   for (int &i : b) {
      cin >> i;
      if (i > 0) {
         pos_b.push_back(i);
      } else {
         neg_b.push_back(-i);
      }
   }
   reverse(all(neg_b));
   reverse(all(neg_a));
   cout << solve(neg_a, neg_b) + solve(pos_a, pos_b) << '\n';
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