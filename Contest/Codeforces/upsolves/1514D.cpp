#include <bits/stdc++.h>
using namespace std;
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   vector<vector<int>> g(n + 1);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      g[a[i]].push_back(i);
   }
   while (q--) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int c = 20, mx = 0;
      while (c--) {
         int in = getRand(l, r);
         int v = upper_bound(all(g[a[in]]), r) - lower_bound(all(g[a[in]]), l);
         mx = max(mx, v);
      }
      int d = r - l + 1;
      if (mx <= (d + 1) / 2) {
         cout << 1 << '\n';
      } else {
         cout << 2 * mx - d << '\n';
      }
   }
   return 0;
}