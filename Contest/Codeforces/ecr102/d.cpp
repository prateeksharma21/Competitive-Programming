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

template<typename T, bool max_mode = true>
class SparseTable {
   int n, lg;
   vector<vector<T>> st;

public:
   SparseTable (vector<T> a) {
      this->n = a.size();
      this->lg = log2(n) + 1;
      st = vector<vector<T>>(n, vector<T>(lg));
      for (int i = 0; i < n; ++i) {
         st[i][0] = a[i];
      }
      compute();
   }

   T op (T a, T b) {
      if (max_mode) return max(a, b);
      return min(a, b);
   }

   void compute() {
      for (int j = 1; j < lg; ++j) {
         for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = op(st[i][j - 1], st[i + (1  << (j - 1))][j - 1]);
         }
      }
   }

   T query(int l, int r) {
      if (l > r) return 0;
      int j = log2(r - l + 1);
      return op (st[l][j], st[r - (1 << j) + 1][j]);
   }
};

void test(){
   int n, m;
   cin >> n >> m;
   string s;
   cin >> s;
   vector<int> mn(n), mx(n);
   int cmn = 0, cmx = 0;
   int sm = 0;
   vector<int> pre(n);
   for (int i = 0; i < n; ++i) {
      sm += (s[i] == '+' ? 1 : -1);
      cmn = min(cmn, sm);
      cmx = max(cmx, sm);
      mn[i] = cmn;
      mx[i] = cmx;
      pre[i] = sm;
   }
   // debug(pre);
   SparseTable<int> smax(pre);
   SparseTable<int, false> smin(pre);

   auto get = [&] (int i) {
      if (i == 0) return 0LL;
      return pre[i - 1];
   };

   auto get_val = [&] (int i) {
      array<int, 2> r;
      if (i == 0) return r = {0, 0};
      return r = {mn[i - 1], mx[i - 1]};
   };

   while (m--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      if (r == n - 1) {
         auto [cmn, cmx] = get_val(l);
         cout << cmx - cmn + 1 << '\n';
         continue;
      }
      int val = get(l);
      int get_max = smax.query(r + 1, n - 1);
      int get_min = smin.query(r + 1, n - 1);
      int prv_val = get(r + 1);
      get_max -= prv_val;
      get_min -= prv_val;
      auto [cmn, cmx] = get_val(l);
      // debug(cmn, cmx);
      // debug(val, get_max, get_min, prv_val);
      cmn = min(cmn, val + get_min);
      cmx = max(cmx, val + get_max);
      cout << cmx - cmn + 1 << '\n';
   }
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