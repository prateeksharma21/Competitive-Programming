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
   for (int &i : a) {
      cin >> i;
   }
   vector<int> b = a;
   sort(all(a));
   int mn = 1e18;
   for (int i = 0; i + 1 < n; ++i) {
      mn = min(mn, a[i + 1] - a[i]);
   }
   for (int i = 0; i + 1 < n; ++i) {
      if (a[i + 1] - a[i] == mn) {
         vector<int> b;
         cout << a[i] << ' ';
         for (int j = 0; j < n; ++j) {
            if (j == i or j == i + 1) continue;
            if (a[j] >= a[i]) {
               cout << a[j] << ' ';
            } else {
               b.push_back(a[j]);
            }
         }
         for (int j : b) {
            cout << j << ' '; 
         }
         cout << a[i + 1] << '\n';
         return;
      }
   }

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