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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m, p;
   cin >> n >> m >> p;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < m; ++j) {
         if (s[j] == '1') {
            a[i] |= (1LL << j);
         }
      }      
   }
   int cnt = 30;
   int ans = 0;
   while (cnt--) {
      int idx = getRand(0, n - 1);
      vector<int> bit;
      for (int j = 0; j < m; ++j) {
         if (a[idx] >> j & 1) {
            bit.push_back(j);
         }
      }
      int sz = bit.size();
      vector<int> cnt(1 << sz);
      for (int i = 0; i < n; ++i) {
         int mask = 0;
         for (int j = 0; j < sz; ++j) {
            if (a[i] >> bit[j] & 1) {
               mask |= (1LL << j);
            }
         }
         cnt[mask]++;
      }
      vector<int> sum(1 << sz);
      for (int mask = (1 << sz) - 1; mask; --mask) {
         if (!cnt[mask]) continue;
         for (int s = mask; s; s = (s - 1) & mask) {
            sum[s] += cnt[mask];
         }
      }
      for (int mask = 1; mask < (1 << sz); ++mask) {
         if (sum[mask] >= (n + 1) / 2 and __builtin_popcountll(mask) > __builtin_popcountll(ans)) {
            ans = 0;
            for (int j = 0; j < sz; ++j) {
               if (mask >> j & 1) {
                  ans |= (1LL << bit[j]);
               }
            }
         }
      }
   }
   for (int i = 0; i < m; ++i) {
      cout << (ans >> i & 1);
   }
   return 0;
}