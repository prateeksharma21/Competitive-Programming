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
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   } 
   for (int i = 0; i < n; ++i) {
      cin >> b[i];
   }
   sort(all(a), greater{});
   sort(all(b), greater{});
   vector<int> preA(n + 1), preB(n + 1);
   for (int i = 0; i < n; ++i) {
      preA[i + 1] = preA[i] + a[i];       
   }
   for (int j = 0; j < n; ++j) {
      preB[j + 1] = preB[j] + b[j];
   }
   int l = n, h = 1e9;
   int ans = h;
   while (l <= h) {
      int m = (l + h) / 2;
      int req = m -  m / 4;
      int val = min(req, m - n);
      int oth = req - val;
      int scA = val * 100 + preA[oth];
      int scB = preB[min(req, n)];
      if (scA >= scB) {
         ans = m;
         h = m - 1;
      } else {
         l = m + 1;
      }
   }
   cout << ans - n << '\n';
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