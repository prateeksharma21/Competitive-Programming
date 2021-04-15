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
   int n, l, r, s;
   cin >> n >> l >> r >> s;
   int t = r - l + 1;
   int c = 1, mn = 0;
   while (t--) {
      mn += c;
      ++c;
   }
   t = r - l + 1;
   c = n;
   int mx = 0;
   while (t--) {
      mx += c;
      --c;
   }
   if (s < mn or s > mx) {
      cout << -1 << '\n';
      return;
   }
   vector<int> v(r - l + 1);
   iota(all(v), 1LL);
   vector<int> other(n - (r - l + 1));
   iota(all(other), r - l + 2);
   int req = s - mn;
   int inc = other.size();
   for (int i = r - l; i >= 0 and req; --i) {
      if (req <= inc) {
         swap(v[i], other[req - 1]);
         req = 0;
      } else {
         swap(v[i], other[inc - 1]);
         sort(all(other));
         req -= inc;
      }
   }
   int j = 0, k = 0;
   for (int i = 1; i <= n; ++i) {
      if (i >= l and i <= r) {
         cout << v[j++] << ' ';
      } else {
         cout << other[k++] << ' ';
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