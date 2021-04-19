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

bool is_prime (int x) {
   if (x < 2 or (x > 2 and x % 2 == 0)) return false;
   for (int i = 3; i * i <= x; i += 2) {
      if (x % i == 0) {
         return false;
      }
   }
   return true;
}

void Solve() {
   int n;
   cin >> n;
   int v = sqrt(n);
   int sq = v;
   while (is_prime(v) == false) --v;
   int m = v;
   if (v == 2) {
      v = sq + 1;
      while (is_prime(v) == false) ++v;
      cout << v * m << '\n';
   } else {
      --v;
      while (is_prime(v) == false) --v;
      int l = v;
      v = sq + 1;
      while (is_prime(v) == false) ++v;
      int r = v;

      if (m * r <= n) {
         cout << m * r << '\n';
      } else {
         cout << l * m << '\n';
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
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}