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

int col[51];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   memset(col, -1, sizeof col);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (col[a[i]] == -1) {
         col[a[i]] = i;
      }
   }
   while (q--) {
      int c;
      cin >> c;
      int v = col[c];
      cout << v + 1 << ' ';
      for (int i = 1; i <= 50; ++i) {
         if (col[i] < v) {
            ++col[i];
         }
      }
      col[c] = 0;
   }
   return 0;
}