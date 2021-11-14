template <typename T, class F = function<T(const T&, const T&)>>
class SegTree{
private:
   int _n, sz, lg;
   vector<T> t, lz;
   T BASE;
   F op;
   T e() {return BASE;}
   void apply(int k) {
      t[k] = op(t[2 * k], t[2 * k + 1]);
   }
   void add(int k, int val) {
      t[k] += val;
      if (k < sz) lz[k] += val;
   }
   void push(int k) {
      add(2 * k, lz[k]);
      add(2 * k + 1, lz[k]);
      lz[k] = 0; 
   }
public:
   SegTree(int n, const F& f, int Base) : SegTree(vector<T>(n, Base), f, Base) {}
   SegTree (vector<T> a, const F& f, int Base) : op(f), BASE(Base), _n(a.size()) {
      lg = 0;
      while ((1U << lg) < _n) ++lg;
      sz = 1 << lg;
      t = vector<T>(2 * sz, e());
      lz = vector<T>(sz, 0);
      for (int i = 0; i < _n; ++i) t[sz + i] = a[i];
      for (int i = sz - 1; i >= 1; --i) {
         apply(i);
      }
   }
   void set(int p, int v) {
      p += sz;
      for (int i = lg; i >= 1; --i) push(p >> i);
      t[p] = v;
      for (int i = 1; i <= lg; ++i) apply(p >> i); 
   }
   T query(int p) {
      p += sz;
      for (int i = lg; i >= 1; --i) push(p >> i);
      return t[p];
   }
   T query(int l, int r) {
      ++r;
      l += sz;
      r += sz;
      for (int i = lg; i >= 1; --i) {
         if (((l >> i) << i) != l) push(l >> i);
         if (((r >> i) << i) != r) push((r - 1) >> i);
      }
      T L = e(), R = e();
      while (l < r) {
         if (l & 1) L = op(L, t[l++]);
         if (r & 1) R = op(t[--r], R);
         l >>= 1;
         r >>= 1;
      }
      return op(L, R);
   }
   void update(int p, T val) {
      p += sz;
      for (int i = lg; i >= 1; --i) push(p >> i);
      t[p] += val;
      for (int i = 1; i <= lg; ++i) apply(p >> i);
   }
   void update(int l, int r, int val) {
      l += sz, r += sz + 1;
      for (int i = lg; i >= 1; --i) {
         if (((l >> i) << i) != l) push(l >> i);
         if (((r >> i) << i) != r) push((r - 1) >> i);
      }
      int l2 = l, r2 = r;
      while (l < r) {
          if (l & 1) add(l++, val);
          if (r & 1) add(--r, val);
          l >>= 1;
          r >>= 1;
      }
      l = l2, r = r2;
      for (int i = 1; i <= lg; i++) {
         if (((l >> i) << i) != l) apply(l >> i);
         if (((r >> i) << i) != r) apply((r - 1) >> i);
     }
   }
};