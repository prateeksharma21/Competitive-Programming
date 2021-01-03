template <typename T>
class SegTreeSum {
public:
   vector<T> t, lazy, A;
   int n;

   SegTreeSum (int n) {
      this->n = n;
      this->t.assign(4 * n + 10, 0);
      this->lazy.assign(4 * n + 10, 0);
   }

   SegTreeSum (vector<T> a) : SegTreeSum (a.size()) {
      this->A = a;
      build(1, 0, n - 1);
   }

   void build (int v, int tl, int tr) {
      if (tl == tr) {
         t[v] = A[tl];
         return;
      }
      int tm = (tl + tr) / 2;
      build (v << 1, tl, tm);
      build (v << 1 | 1, tm + 1, tr);
      t[v] = t[v << 1] + t[v << 1 | 1];
   }

   void push (int v, int tl, int tr) {
      if (lazy[v]) {
         t[v] += (tr - tl + 1) * lazy[v];
         if (tl != tr) {
            lazy[v << 1] += lazy[v];
            lazy[v << 1 | 1] += lazy[v];
         }
         lazy[v] = 0;
      }
   }

   void update (int v, int tl, int tr, int l, int r, T val) {
      push (v, tl, tr);
      if (tl > r or tr < l) return;
      if (tl >= l and tr <= r) {
         lazy[v] += val;
         push (v, tl, tr);
         return;
      }
      int tm = (tl + tr) / 2;
      update (v << 1, tl, tm, l, r, val);
      update (v << 1 | 1, tm + 1, tr, l, r, val);
      t[v] = t[v << 1] + t[v << 1 | 1];
   }

   T query (int v, int tl, int tr, int l, int r) {
      if (tr < l or tl > r) return 0;
      push (v, tl, tr);
      if (tl >= l and tr <= r) return t[v];
      int tm = (tl + tr) / 2;
      return query (v << 1, tl, tm, l, r) + 
             query (v << 1 | 1, tm + 1, tr, l, r);
   }

   T query (int l, int r) {
      return query (1, 0, n - 1, l, r);
   }

   T query (int p) {
      return query (1, 0, n - 1, p, p);
   }

   void update (int l, int r, T val) {
      update (1, 0, n - 1, l, r, val);
   }

   void update (int p, T val) {
      update (1, 0, n - 1, p, p, val);
   }
};