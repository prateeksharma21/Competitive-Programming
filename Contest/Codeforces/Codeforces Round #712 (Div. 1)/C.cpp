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

template <typename T, bool max_mode = true>
class SegTree{
public:
   vector<T> t, lazy, A;
   int n;

   SegTree (int n) {
      this->n = n;
      this->t.assign(4 * n + 10, 0);
      this->lazy.assign(4 * n + 10, 0);
   }

   SegTree (vector<T> a) : SegTree (a.size()) {
      this->A = a;
      build (1, 0, n - 1);
   }

   T op (T a,T b){
      if (max_mode) return max(a, b);
      return min(a, b);
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
         if (max_mode) return -1e18;
         return 1e18;
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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<array<int, 3>> A(n);
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      A[i] = {x, y, i};
      ans += y;
   }
   sort(all(A));
   vector<int> b(n);
   for (int i = 0; i < n; ++i) {
      b[i] = A[i][0];
   }
   SegTree<int, false> dp(n);
   SegTree<int, false> dp2(n);
   dp2.update(n - 1, A[n - 1][0]);
   for (int i = n - 2; i >= 0; --i) {
      auto k = upper_bound(all(b), A[i][0] + A[i][1]) - b.begin();
      int val;
      if (k == n) {
         val = dp.query(i + 1, n - 1);
      } else if (k == i + 1) {
         val = dp2.query(i + 1, n - 1) - (A[i][0] + A[i][1]);
      } else {
         val = min(dp.query(i + 1, k - 1), dp2.query(k, n - 1) - (A[i][0] + A[i][1]));
      }  
      dp.update(i, val);
      dp2.update(i, val + A[i][0]);
   }
   ans += dp.query(0); 
   cout << ans << '\n';
   return 0;
}