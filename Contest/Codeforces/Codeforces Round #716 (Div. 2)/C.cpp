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
   vector<int> can(n);
   vector<int> f;
   for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
         f.push_back(i);
         if (i * i != n) {
            f.push_back(n / i);
         }
      }
   }
   for (int i : f) {
      for (int j = i; j < n; j += i) {
         can[j] = 1;
      }
   }
   vector<int> res;
   int m = 1;
   for (int i = 1; i < n - 1; ++i) {
      if (!can[i]) {
         m *= i;
         m %= n;
         res.push_back(i);
      }
   }
   m *= (n - 1);
   m %= n;
   if (m == 1) res.push_back(n - 1);
   cout << res.size() << '\n';
   for (int i : res) {
      cout << i << ' ';
   }
   return 0;
}