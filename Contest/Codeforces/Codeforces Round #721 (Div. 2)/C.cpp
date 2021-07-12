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

int solve(vector<int> a, int mx) {
   int ans = 0;
   int n = a.size();
   int sum = 0;
   for (int i : a) sum += i;
   for (int i = 0; i < n; ++i) {
      sum -= a[i];
      ans += (a[i] * ((mx + 1) * (n - i - 1) - sum));
   }
   return ans;
}

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   map<int, vector<int>> pos;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]].push_back(i + 1);
   }

   int ans = 0;

   for (auto &e : pos) {
      ans += solve(e.second, n);
   }

   cout << ans << '\n';
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