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
const int MOD = 1e9+7, N = 500;
const int P = 500;
const int MX = 1e18;

int spf[N];
int cnt[P];

vector<int> prime;

void Solve() {
   int m;
   cin >> m;
   vector<pair<int, int>> a;
   int mx = 0;
   for (int i = 0; i < m; ++i) {
      int x, v;
      cin >> x >> v;
      a.push_back({x, v});
      mx += x * v;
      cnt[x] += v;
   } 
   for (int j = mx; j >= max(2LL, mx - 500 * 60); --j) {
      vector<int> pr;
      int x = j;
      int c = 1;
      int tot = mx;
      for (int v : prime) {
         while (x % v == 0) {
            if (!cnt[v]) {
               c = 0;
               break;
            }
            pr.push_back(v);
            tot -= v;
            --cnt[v];
            x /= v;
         }
      }
      if (c and x == 1 and tot == j) {
         cout << j << '\n';
         for (auto [x, y] : a) {
            cnt[x] = 0;
         }
         return;
      }
      for (int i : pr) cnt[i]++;
   }
   for (auto [x, y] : a) {
      cnt[x] = 0;
   }
   cout << 0 << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   for (int i = 2; i < N; ++i) {
      if (spf[i] == 0) {
         spf[i] = i;
         prime.push_back(i);
         for (int j = i * i; j < N; j += i) {
            if (!spf[j]) spf[j] = i;
         }
      }
   }

   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}