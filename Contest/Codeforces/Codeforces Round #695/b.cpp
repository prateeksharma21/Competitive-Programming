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
   int ans = 0;

   auto hill = [&] (int i) {
      return a[i] > a[i - 1] and a[i] > a[i + 1];
   };

   auto valley = [&] (int i) {
      return a[i] < a[i - 1] and a[i] < a[i + 1];
   };

   for (int i = 1; i + 1 < n; ++i) {
      ans += hill(i) + valley(i);
   }

   auto dec = [&] (int i) {
      int st = max(1LL, i - 1);
      int en = min(n - 2, i + 1);
      for (int j = st; j <= en ; ++j) {
         ans -= (hill(j) + valley(j));
      }
   };

   auto inc = [&] (int i) {
      int st = max(1LL, i - 1);
      int en = min(n - 2, i + 1);
      for (int j = st; j <= en ; ++j) {
         ans += (hill(j) + valley(j));
      }
   };

   int res = ans;
   for (int i = 1; i + 1 < n; ++i) {
      int tmp = a[i];
      dec(i);
      a[i] = a[i - 1];
      inc(i);
      res = min(res, ans);
      dec(i);
      a[i] = a[i + 1];
      inc(i);
      res = min(res, ans); 
      dec(i);
      a[i] = tmp;
      inc(i);
   }
   cout << res << '\n';
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