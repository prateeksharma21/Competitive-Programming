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
      int n, m;
   cin >> n >> m;
   vector<int> chk(1001);
   for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      for (int i = l; i <= r; ++i) {
         chk[i] = 1;
      }
   }
   vector<int> res;
   for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      int nxt = 1000000;
      for (int j = x; j <= 1000; ++j) {
         if (chk[j]) {
            nxt = j;
            break;
         }
      }
      int prv = -10000000;
      for (int j = x - 1; j > 0; --j) {
         if (chk[j]) {
            prv = j;
            break;
         }
      }
      if (x - prv <= nxt - x) {
         res.push_back(prv);
         chk[prv] = 0;
      } else {
         res.push_back(nxt);
         chk[nxt] = 0;
      }
   }
   for (int i : res) {
      cout << i << ' ';
   }
   cout << '\n';
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