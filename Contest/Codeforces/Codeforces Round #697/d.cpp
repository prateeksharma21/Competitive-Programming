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
   vector<int> a(n), b(n);
   int sm = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sm += a[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> b[i];
   }
   // debug(sm);
   if (sm < m) {
      cout << -1 << '\n';
      return;
   }
   int l = 1, r = accumulate(all(b), 0LL);
   int ans;

   vector<int> one, two;
   for (int i = 0; i < n; ++i) {
      if (b[i] == 1) {
         one.push_back(a[i]);
      } else {
         two.push_back(a[i]);
      }
   }

   sort(all(one), greater{});
   sort(all(two), greater{});

   vector<int> one_two = two;
   for (int i = 0; i + 1 < one.size(); i += 2) {
      one_two.push_back(one[i] + one[i + 1]);
   }
   if ((int)one.size() & 1) {
      one_two.push_back(one.back());
   }
   sort(all(one_two), greater{});

   vector<int> one_two_n = two;
   for (int i = 1; i + 1 < one.size(); i += 2) {
      one_two_n.push_back(one[i] + one[i + 1]);
   }
   if ((int)one.size() % 2 == 0 and !one.empty()) {
      one_two_n.push_back(one.back());
   }
   sort(all(one_two_n), greater{});

   auto can_remove = [&] (int pt) {
      if (pt % 2 == 0) {
         int val = 0;
         int sz = one_two.size();
         for (int i = 0; i < min(sz, pt / 2); ++i) {
            val += one_two[i];
         }
         return val >= m;
      }
      if (one.empty()) {
         int sz = two.size();
         int val = 0;
         for (int i = 0; i < min(sz, pt / 2); ++i) {
            val += two[i];
         }
         return val >= m;
      }
      int val = one.front();
      --pt;
      int sz = one_two_n.size();
      for (int i = 0; i < min(sz, pt / 2); ++i) {
         val += one_two_n[i];
      }
      return val >= m;
   };

   while (l <= r) {
      int m = (l + r) / 2;
      if (can_remove(m)) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }
   cout << ans << '\n';
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