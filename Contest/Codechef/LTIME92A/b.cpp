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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   int sm = 0;
   vector<int> b;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] %= k;
      if (a[i])
         b.push_back(a[i]);
   }
   if (b.empty()) {
      cout << "YES\n";
      return;
   }
   sort(all(b));
   int sz = b.size();
   int l = 0, h = sz - 1;
   bool c = 0;
   // if (sz & 1) {
   //    for (int i = 0; i < sz; ++i) {
   //       int md = b[i];
   //       while (md < k) md *= 2;
   //       c |= (md == k);
   //    }
   // }
   // if (sz & 1 and !c) {
   //    cout << "NO\n";
   //    return;
   // }
   while (l < h) {
      if ((b[l] + b[h]) % k != 0) {
         cout << "NO\n";
         return;
      }
      ++l;
      --h;
   }
   cout << "YES\n";
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