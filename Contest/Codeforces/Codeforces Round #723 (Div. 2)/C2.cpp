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
   vector<int> a(n);
   multiset<int> neg;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int sum = 0, ans = 0;
   for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (sum < 0) {
         sum -= a[i];
         if (neg.empty()) {
            continue;
         }
         auto k = *neg.begin();
         if (k < a[i]) {
            neg.erase(neg.begin());
            sum -= k;
            sum += a[i];
            assert(sum >= 0);
            neg.insert(a[i]);
            continue;            
         }
         continue;
      }
      if (a[i] < 0) neg.insert(a[i]);
      ++ans;
   }
   debug(neg);
   cout << ans << '\n';
   return 0;
}