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
const int MOD = 1e9+7, N = 2e5 + 10; 

int a[4 * N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> k;
   string s;
   cin >> s;
   n = (1 << k);
   reverse(all(s));
   s = "#" + s;
   fill(a, a + 4 * N, 1);
   for (int i = n; i >= 1; --i) {
      if (s[i] == '?') {
         a[i] = a[i * 2] + a[i * 2 + 1];
      } else if (s[i] == '1') {
         a[i] = a[i * 2]; 
      } else {
         a[i] = a[i * 2 + 1];
      }
   }
   int q;
   cin >> q;

   function<void(int)> propagate = [&](int p) {
      if (p == 1) return;
      int pr = p / 2;
      if (s[pr] == '?') {
         a[pr] = a[pr * 2] + a[pr * 2 + 1];
      } else if (s[pr] == '1') {
         a[pr] = a[pr * 2];
      } else {
         a[pr] = a[pr * 2 + 1];
      }
      propagate(pr);
   };

   while (q--) {
      int p;
      char c;
      cin >> p >> c;
      p = n - p;
      if (c == '?') {
         a[p] = a[2 * p] + a[2 * p + 1];
      } else if (c == '1') {
         a[p] = a[p * 2];
      } else {
         a[p] = a[p * 2 + 1];
      }
      propagate(p);
      s[p] = c;
      cout << a[1] << '\n';
   }
   return 0;
}