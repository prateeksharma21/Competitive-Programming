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
   vector<int> a(2 * n);
   int g = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i + n] = a[i];
      g = gcd(g, a[i]);
   }
   for (int &i : a) i /= g;
   SparseTable<int> st(a);
   int l = 1, r = n;
   int ans = -1;
   while (l <= r) {
      int m = (l + r) / 2;
      int chk = 1;
      for (int i = 0; i < n; ++i) {
         if (st.query(i, i + m - 1) != 1) {
            chk = 0;
            break;
         }
      }
      if (chk) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }
   cout << ans - 1 << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 100;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}