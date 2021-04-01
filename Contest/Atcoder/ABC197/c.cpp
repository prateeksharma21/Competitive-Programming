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
   vector<int> A(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> A[i];
   }

   int ans = 1e18;

   function<void(int, vector<int>)> solve = [&](int i, vector<int> a) {
      if (i == n + 1) {
         int v = 0;
         for (int j : a) {
            v ^= j;
         }
         ans = min(ans, v);
         return;
      }

      int cur = 0;
      for (int j = i; j <= n; ++j) {
         cur |= A[j];
         a.push_back(cur);
         solve(j + 1, a);
         a.pop_back();
      }
   };


   solve(1, {});

   cout << ans << '\n';
   return 0;
}