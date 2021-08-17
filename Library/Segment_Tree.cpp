template<typename T, class F = function<T(const T&, const T&)>>
class SegmentTree {
private:
   int _n, sz, lg;
   T BASE;
   vector<T> t;
   F op;
   T e() {return BASE;}
   void apply(int k) {
      t[k] = op(t[2 * k], t[2 * k + 1]);
   }   
public:
   SegmentTree(int n, const F& f, int Base) {
      BASE = Base;
      SegmentTree(vector<T>(n, e()), f, Base);
   }
   SegmentTree(vector<T> &a, const F& f, T Base) : op(f), BASE(Base), _n(a.size()) {
      lg = 0;
      while ((1U << lg) < _n) ++lg;
      sz = 1 << lg;
      t = vector<T>(2 * sz, e());
      for (int i = 0; i < _n; ++i) t[sz + i] = a[i];
      for (int i = sz - 1; i >= 1; --i) {
         apply(i);
      }
   }
   void update(int p, T x) {
      assert(0 <= p and p < _n);
      p += sz;
      t[p] = x;
      for (int i = 1; i <= lg; ++i) apply(p >> i);
   }
   T query(int p) {
      return t[p + sz];
   }
   T query(int l, int r) {
      assert(0 <= l and l <= r and r < _n);
      ++r;
      T L = e(), R = e();
      l += sz, r += sz;
      while (l < r) {
         if (l & 1) L = op(L, t[l++]);
         if (r & 1) R = op(t[--r], R);
         l >>= 1, r >>= 1;
      }
      return op(L, R);
   }
};