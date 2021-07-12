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
   int n, l, r;
   cin >> n >> l >> r;
   vector<int> a(n);
   vector<int> cl(n), cr(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
   }
   for (int i = 0; i < l; ++i) {
      cl[a[i]]++;
   }
   for (int i = l; i < n; ++i) {
      cr[a[i]]++;
   }
   int rem_L = 0, rem_R = 0;
   for (int i = 0; i < n; ++i) {
      int mn = min(cl[i], cr[i]);
      cl[i] -= mn;
      cr[i] -= mn;
      rem_L += cl[i];
      rem_R += cr[i];
   }


   int ans = min(rem_R, rem_L);
   int cur = ans;
   for (int i = 0; i < n and cur; ++i) {
      if (cl[i] & 1) {
         --cl[i];
         --cur;
      }
   }   
   for (int i = 0; i < n; ++i) {
      while (cl[i] and cur > 1) {
         cl[i] -= 2;
         cur -= 2;
      }
      if (cur == 1 and cl[i]) {
         --cl[i];
         --cur;
      }
   }

   cur = ans;
   for (int i = 0; i < n and cur; ++i) {
      if (cr[i] & 1) {
         --cr[i];
         --cur;
      }
   }   
   for (int i = 0; i < n; ++i) {
      while (cr[i] and cur > 1) {
         cr[i] -= 2;
         cur -= 2;
      }
      if (cur == 1 and cr[i]) {
         --cr[i];
         --cur;
      }
   }

   int L = 0, R = 0;

   for (int i = 0; i < n; ++i) {
      {
         int hf = cl[i] / 2;
         ans += hf;
         cl[i] -= 2 * hf;
      }
      {
         int hf = cr[i] / 2;
         ans += hf;
         cr[i] -= 2 * hf;
      }
      L += cl[i];
      R += cr[i];
   }

   ans += (L + R);
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