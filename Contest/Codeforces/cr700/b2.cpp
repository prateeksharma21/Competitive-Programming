#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define K a
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int a[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<vector<int>> pos(n + 1);
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      pos[a[i]].push_back(i);
   }
   for (int i = 1; i <= n; ++i) {
      reverse(all(pos[i]));
   }
   int prv[2] = {0, 0};
   for (int i = 0; i < n; ++i) {
      pos[K[i]].pop_back();
      if (K[i] == prv[0]) {
         if (K[i] == prv[1]) {

         } else {
            ++ans;
            prv[1] = K[i];
         }
         continue;
      }
      if (K[i] == prv[1]) {
         ++ans;
         prv[0] = K[i];
         continue;
      }
      ++ans;
      if (prv[0] == 0) {
         prv[0] = K[i];
         continue;
      }
      if (prv[1] == 0) {
         prv[1] = K[i];
         continue;
      }
      if (pos[prv[0]].empty()) {
         prv[0] = K[i];
         continue;
      }
      if (pos[prv[1]].empty()) {
         prv[1] = K[i];
         continue;
      }
      if (pos[prv[0]].back() > pos[prv[1]].back()) {
         prv[1] = K[i];
      } else {
         prv[0] = K[i];
      }
   }
   cout << ans << '\n';
   return 0;
}