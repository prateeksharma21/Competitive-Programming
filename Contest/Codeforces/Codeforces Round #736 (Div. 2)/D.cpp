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

template<typename T>
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
      return gcd(a, b);
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
   vector<int>  a(n);
   for (int &i : a) {
      cin >> i;
   }
   if (n == 1) {
      cout << 1 << '\n';
      return;
   }
   vector<int> b(n - 1);
   for (int i = 0; i + 1 < n; ++i) {
      b[i] = abs(a[i] - a[i + 1]);
   }
   SparseTable<int> st(b);
   auto can = [&](int k) -> bool {
      for (int i = 0; i + k - 1 < n; ++i) {
         // debug(st.query(i, i + k - 2), i, i + k - 2);
         if (st.query(i, i + k - 2) != 1) return true;
      }
      return false;
   };

   int l = 2, r = n, ans = 1;
   while (l <= r) {
      int m = (l + r) / 2;
      if (can(m)) {
         ans = m;
         l = m + 1;
      } else {
         r = m - 1;
      }
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