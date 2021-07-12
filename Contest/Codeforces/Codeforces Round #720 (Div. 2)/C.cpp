#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#include <bits/stdc++.h>
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int c = 0;

int query(int t, int i, int j, int x) {
   cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
   cin >> x;
   ++c;
   return x;
}

void test(){
   int n;
   cin >> n;
   int fnd = n;
   for (int i = 1; i + 1 <= n; i += 2) {
      int v = query(2, i, i + 1, 1);
      if (v == 1) {
         fnd = i;
         break;
      }
      if (v == 2 and query(2, i + 1, i, 1) == 1) {
         fnd = i + 1;
         break;
      }
   }
   vector<int> res(n + 1);
   for (int i = 1; i <= n; ++i) {
      if (i == fnd) {
         res[i] = 1;
      } else {
         res[i] = query(1, fnd, i, n - 1);
      }
   }
   cout << "! ";
   for (int i = 1; i <= n; ++i) {
      cout << res[i] << ' ';
   }
   cout << endl;
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