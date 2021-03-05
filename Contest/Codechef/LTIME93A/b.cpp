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
      int j = log2(r - l + 1);
      return op (st[l][j], st[r - (1 << j) + 1][j]);
   }
};

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<int> nxt(n, -1);
   vector<int> stk;
   for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() and a[stk.back()] < a[i]) {
         stk.pop_back();
      }
      if (!stk.empty()) {
         nxt[i] = stk.back();
      }
      stk.push_back(i);
   }

   vector<int> prv(n, -1);
   stk.clear();
   for (int i = 0; i < n; ++i) {
      while (!stk.empty() and a[stk.back()] < a[i]) {
         stk.pop_back();
      }
      if (!stk.empty()) {
         prv[i] = stk.back();
      }
      stk.push_back(i);
   }

   int ans = 0;
   set<int> s;
   for (int i = 0; i < n; ++i) {
      if (i != 0) {
         int p = i - 1;
         while (p != -1 and a[p] <= a[i]) {
            s.insert(a[i] - a[p]);
            p = prv[p];
         }
      }
      if (i != n - 1) {
         int p = i + 1;
         while (p != -1 and a[p] <= a[i]) {
            s.insert(a[i] - a[p]);
            p = nxt[p];
         }
      }
   }
   cout << s.size() << '\n';
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