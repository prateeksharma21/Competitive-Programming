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
   map<int, int> val;
   int n;
   cin >> n;
   int r = 0;
   int increment = 0;
   while (n--) {
      int ty;
      cin >> ty;
      if (ty == 1) {
         int x;
         cin >> x;
         val[x - increment]++;
         ++r;
      } else if (ty == 2) {
         int x;
         cin >> x;
         increment += x;
      } else {
         int ans = val.begin()->first;
         cout << ans + increment << '\n';
         --val[ans];
         --r;
         if (val[ans] == 0) {
            val.erase(ans);
         }
      }
   }
   return 0;
}