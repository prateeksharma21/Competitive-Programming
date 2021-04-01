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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i : a) {
      cin >> i;
   }
   vector<int> val_f(n), val_l(n);
   for (int i = 0; i < n; ++i) {
      val_f[i] = 1;
      if (i > 0 and a[i] > a[i - 1]) {
         val_f[i] += val_f[i - 1];
      } 
   }
   set<pair<int, int>> val;
   for (int i = n - 1; i >= 0; --i) {
      val_l[i] = 1;
      if (i + 1 < n and a[i] > a[i + 1]) {
         val_l[i] += val_l[i + 1];
      }
      val.insert({max(val_f[i], val_l[i]), i});
   }
   int ans = 0;
   debug(val_l);
   debug(val_f);
   for (int i = 1; i + 1 < n; ++i) {
      int mx = max(val_l[i], val_f[i]);
      val.erase({mx, i});
      if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
         if ((*prev(val.end())).first < mx) {
            int c = 0;
            if (val_l[i] > 1) {
               int L = val_l[i] - 1, R = val_f[i];
               int k = 0;
               k += (R < L);
               k += (L % 2 == 0);
               c |= (k == 2);
            }
            {
               int L = val_l[i], R = val_f[i];
               int k = 0;
               k += (R < L);
               k += (L % 2 == 0);
               c |= (k == 2);  
            }
            if (val_f[i] > 1) {
               int L = val_l[i], R = val_f[i] - 1;
               swap(L, R);
               int k = 0;
               k += (R < L);
               k += (L % 2 == 0);
               c |= (k == 2);
            }
            {
               int L = val_l[i], R = val_f[i];
               swap(L, R);
               int k = 0;
               k += (R < L);
               k += (L % 2 == 0);
               c |= (k == 2);
            }
            ans += 1 - c;
         }
      }
      val.insert({mx, i});
   }
   cout << ans << '\n';
   return 0;
}