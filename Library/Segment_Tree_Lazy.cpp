template <typename T, class F = function<T(const T&, const T&)>>
class SegTree{
private:
   vector<T> t, lazy, A;
   int n;
   T BASE;
   F op;

public:
   SegTree (int n, const F& f, int Base) : op(f), BASE(Base) {
      this->n = n;
      this->t.assign(4 * n + 10, 0);
      this->lazy.assign(4 * n + 10, 0);
   }

   SegTree (vector<T> a, const F& f, int Base) : SegTree(a.size(), f, Base) {
      this->A = a;
      build (1, 0, n - 1);
   }

   void build (int v,int tl,int tr){
      if (tl == tr) {
         t[v] = A[tl];
      } else {
         int tm = (tl + tr) / 2;
         build (v << 1, tl, tm);
         build (v << 1 | 1, tm + 1, tr);
         t[v] = op (t[v << 1], t[v << 1 | 1]);
      }
   }

   void push (int v) {
      t[v << 1] += lazy[v];
      lazy[v << 1] += lazy[v];
      t[v << 1 | 1] += lazy[v];
      lazy[v << 1 | 1] += lazy[v];
      lazy[v] = 0;
   }

   void update (int v, int tl, int tr, int l, int r, T addend) {
      if (l > r) return;
      if (l == tl && tr == r) {
         t[v] += addend;
         lazy[v] += addend;
      } else {
         push (v);
         int tm = (tl + tr) / 2;
         update (v << 1, tl, tm, l, min(r, tm), addend);
         update (v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, addend);
         t[v] = op (t[v << 1], t[v << 1 | 1]);
      }
   }

   T query (int v, int tl, int tr, int l, int r) {
      if (l > r) {
         return BASE;
      }
      if (l <= tl && tr <= r)
         return t[v];
      push (v);
      int tm = (tl + tr) / 2;
      return op (query (v << 1, tl, tm, l, min(r, tm)), 
                 query (v << 1 | 1, tm+1, tr, max(l, tm+1), r));
   }

   void update (int l, int r, T val){
      update (1, 0, n-1, l, r, val);
   }

   void update (int i, T val) {
      update (i, i, val);
   }

   T query (int l,int r) {
      return query (1, 0, n-1, l, r);
   }

   T query (int i) {
      return query (i, i);
   }
};