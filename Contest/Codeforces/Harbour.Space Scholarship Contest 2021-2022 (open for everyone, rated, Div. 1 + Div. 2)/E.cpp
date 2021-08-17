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

void test(){
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   vector<int> cnt(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      cnt[(n + i - a[i]) % n]++;
   }
   vector<int> res;
   // debug(cnt);
   for (int k = 0; k < n; ++k) {
      if (cnt[k] * 3 < n) continue;
      // debug(k);
      vector<int> vis(n);
      int ans = 0;
      for (int i = 0; i < n; ++i) {
         if (!vis[i]) {
            int v = i;
            while (!vis[v]) {
               vis[v] = true;
               v = a[(v + k) % n];
            }
            ++ans;
         }
      }
      // debug(ans);
      if (n - ans <= m) res.push_back(k);
   }
   cout << res.size() << ' ';
   for (int i : res) cout << i << ' ';
   cout << '\n';
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