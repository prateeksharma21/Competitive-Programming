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
const int MOD = 1e9+7, N = 5e6 + 10; 

int l[N], r[N];
int a[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
         int k = a[i] + a[j];
         if (l[k]) {
            if (l[k] != i and l[k] != j and r[k] != i and r[k] != j) {
               cout << "YES\n";
               cout << l[k] << ' ' << r[k] << ' ' << i << ' ' << j << '\n';
               return 0;
            }
         } else {
            l[k] = i;
            r[k] = j;
         }
      }
   }
   cout << "NO\n";
   return 0;
}