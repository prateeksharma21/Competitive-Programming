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
const int INF = 1e18;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<array<int, 2>> a(n);
   for (auto &[x, y] : a) {
      cin >> y >> x;
   }
   sort(all(a));

   debug(a);

   vector<int> prv = {0};

   map<int, int> dp;
   dp[0] = 0;

   for (int i = 0, j = 0; i < n; i = j) {
      vector<int> k;
      while (j < n and a[i][0] == a[j][0]) {
         k.push_back(a[j][1]);
         ++j;
      }
      sort(all(k));
      if (k.size() == 1) {
         dp[k.back()] = INF;
         for (int l : prv) {
            dp[k.back()] = min(dp[k.back()], dp[l] + abs(l - k.back()));
         }
         prv = k;
      } else {
         k = {k.front(), k.back()};
         dp[k.back()] = INF;

         for (int l : prv) {
            dp[k.back()] = min(dp[k.back()], dp[l] + abs(l - k.front()) + abs(k.front() - k.back()));
         }

         dp[k.front()] = INF;

         for (int l : prv) {
            dp[k.front()] = min(dp[k.front()], dp[l] + abs(l - k.back()) + abs(k.back() - k.front()));
         }

         prv = k;
      }
   }

   int ans = 1e18;

   for (int i : prv) ans = min(ans, dp[i] + abs(i));

   cout << ans << '\n';
   return 0;
}