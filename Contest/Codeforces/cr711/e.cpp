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

string query(int u, int v) {
   cout << "? " << u << ' ' << v << endl;
   string x;
   cin >> x;
   return x;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<array<int, 2>> a(n);
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i] = {x, i + 1};
   }
   sort(all(a));

   vector<array<int, 3>> K;

   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         K.push_back({a[i][0] - a[j][0], a[j][1], a[i][1]});
      }
   }

   sort(all(K));

   for (auto [_, x, y] : K) {
      if (query(x, y) == "Yes") {
         cout << "! " << x << ' ' << y << endl;
         return 0;
      }
   }

   cout << "! 0 0" << endl;
   return 0;
}