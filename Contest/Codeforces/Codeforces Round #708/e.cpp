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
const int MOD = 1e9+7, N = 1e7 + 10;

int spf[N];

void test(){
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   map<vector<int>, bool> found;

   auto get = [&] (int x) {
      vector<int> res;
      while (spf[x]) {
         int c = 0;
         int v = spf[x];
         while (x % v == 0) {
            ++c;
            x /= v;
         }
         if (c & 1) {
            res.push_back(v);
         }
      }
      return res;
   };


   int ans = 0;

   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      vector<int> f = get(a[i]);
      sort(all(f));
      if (found[f]) {
         ++ans;
         found.clear();
      }
      found[f] = true;
   }

   cout << ans + 1 << '\n';

   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   for (int i = 2; i < N; ++i) {
      if (spf[i] == 0) {
         spf[i] = i;
         for (int j = i * i; j < N; j += i) {
            if (!spf[j]) spf[j] = i;
         }
      }
   }
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}