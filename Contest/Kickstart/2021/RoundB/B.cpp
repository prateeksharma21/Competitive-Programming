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

void Solve() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   if (n == 2) {
      cout << 2 << '\n';
      return;
   }
   vector<int> pre(n), suff(n);
   pre[0] = 1;
   pre[1] = 2;
   int ans = 2;
   for (int i = 2; i < n; ++i) {
      if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
         pre[i] = pre[i - 1] + 1;
      } else {
         pre[i] = 2;
      }
      ans = max(ans, pre[i]);
   }

   suff[n - 1] = 1;
   suff[n - 2] = 2;
   for (int i = n - 3; i >= 0; --i) {
      if (a[i] - a[i + 1] == a[i + 1] - a[i + 2]) {
         suff[i] = suff[i + 1] + 1;
      } else {
         suff[i] = 2;
      }
      ans = max(ans, suff[i]);
   }


   // changed element at 0:
   if (a[1] - a[0] != a[2] - a[1]) {
      ans = max(ans, suff[1] + 1);
   }

   // suppose change at n - 1:
   if (a[n - 1] - a[n - 2] != a[n - 2] - a[n - 3]) {
      ans = max(ans, pre[n - 2] + 1);
   }

   ans = max(ans, 3LL);

   for (int i = 1; i + 1 < n; ++i) {
      int d1 = a[i] - a[i - 1];
      int d2 = a[i + 1] - a[i];
      if ((abs(d1) + abs(d2)) % 2 == 0) {
         int m = (d1 + d2) / 2;
         int v = 1;
         if (i + 2 < n) {
            if (a[i + 2] - a[i + 1] == m) {
               v += suff[i + 1];
            } else {
               v += 1;
            }
         } else {
            v += 1;
         }

         if (i - 2 >= 0) {
            if (a[i - 1] - a[i - 2] == m) {
               v += pre[i - 1];
            } else {
               v += 1;
            }
         } else {
            v += 1;
         }
         ans = max(ans, v);
      }

      {
         if (i + 2 < n) {
            if (a[i + 2] - a[i + 1] != a[i + 1] - a[i]) {
               ans = max(ans, suff[i + 1] + 1);
            }
         }

         if (i - 2 >= 0) {
            if (a[i - 1] - a[i - 2] != a[i] - a[i - 1]) {
               ans = max(ans, pre[i - 1] + 1);
            }
         }
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
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}