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