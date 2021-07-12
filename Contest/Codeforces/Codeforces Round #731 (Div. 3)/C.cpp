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
   int k, n, m;
   cin >> k >> n >> m;
   vector<int> a(n), b(m);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < m; ++i) {
      cin >> b[i];
   }
   int i = 0, j = 0;
   vector<int> r;
   while (i < n and j < m) {
      if (a[i] == 0) {
         r.push_back(a[i]);
         i++;
      } else if (b[j] == 0) {
         r.push_back(b[j]);
         ++j;
      } else {
         if (a[i] < b[j]) {
            r.push_back(a[i]);
            ++i;
         } else {
            r.push_back(b[j]);
            ++j;
         }
      }
   }
   while (i < n) r.push_back(a[i++]);
   while (j < m) r.push_back(b[j++]);
   int cur = k;
   for (int i : r) {
      if (i == 0) {
         ++cur;
      } else {
         if (i > cur) {
            cout << -1 << '\n';
            return;
         }
      }
   }
   for (int i : r) cout << i << ' ';
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