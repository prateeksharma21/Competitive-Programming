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
   int ans = 0;
   for (int mask = 0; mask < (1 << n); ++mask) {
      vector<int> pos;
      for (int i = 0; i < n; ++i) {
         if (mask >> i & 1) {
            pos.push_back(i);
         }
      }
      int c = 0;
      for (int i = 1; i < pos.size(); ++i) {
         if (pos[i] - pos[i - 1] > 2) {
            c = 1;
            break;
         }
      }
      if (c) continue;
      if (pos.empty()) continue;
      if (pos.front() != 0 or pos.back() != n - 1) continue;
      do {
         int b = 1;
         vector<int> L(n);
         for (int i = 0; i < pos.size(); ++i) {
            int v = pos[i];
            if (v - 1 >= 0 and v + 1 < n and L[v - 1] and L[v + 1]) {
               b = 0;
               break;
            }
            L[v] = 1;
         }
         for (int i = 0; i < n; ++i) {
            if (L[i] == 0) {
               b &= (i - 1 >= 0 and i + 1 < n and L[i - 1] and L[i + 1]);
            }
         }
         ans += b;
         if (b) {
            ++c;
            // debug(pos);
         }
      } while (next_permutation(all(pos)));
      debug(pos);
      cout << c << '\n';
      cout << '\n';
   }
   cout << ans << '\n';
   return 0;
}