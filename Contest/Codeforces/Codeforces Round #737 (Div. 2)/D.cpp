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

template <typename T, class F = function<T(const T&, const T&)>>
class SegTree{
private:
   vector<T> t, lazy, A;
   int n;
   T BASE;
   F op;

public:
   SegTree (int n, const F& f, T Base) : op(f), BASE(Base) {
      this->n = n;
      this->t.assign(4 * n + 10, Base);
      this->lazy.assign(4 * n + 10, Base);
   }

   SegTree (vector<T> a, const F& f, T Base) : SegTree(a.size(), f, Base) {
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
      t[v << 1] = max(t[v << 1], lazy[v]);
      lazy[v << 1] = max(lazy[v << 1], lazy[v]);
      t[v << 1 | 1] = max(t[v << 1 | 1], lazy[v]);
      lazy[v << 1 | 1] = max(lazy[v << 1 | 1], lazy[v]);
      lazy[v] = {0, 0};
   }

   void update (int v, int tl, int tr, int l, int r, T addend) {
      if (l > r) return;
      if (l == tl && tr == r) {
         t[v] = max(t[v], addend);
         lazy[v] = max(lazy[v], addend);
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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   cin >> n >> m;
   vector<array<int, 3>> a(m);
   map<int, int> mp;
   for (int i = 0; i < m; ++i) {
      int t, l, r;
      cin >> t >> l >> r;
      mp[l];
      mp[r];
      a[i] = {t, l, r};  
   }
   int c = 0;
   for (auto &e : mp) {
      e.second = c++;
   }
   for (auto &[t, x, y] : a) {
      x = mp[x];
      y = mp[y];
   }
   sort(all(a));
   SegTree<array<int, 2>> st(c, [&](array<int, 2> x, array<int, 2> y){
      return max(x, y);
   }, array<int, 2>({0, 0}));
   vector<array<int, 2>> dp(n + 1);
   for (int i = 0, j = 0; i < m; i = j) {
      vector<array<int, 2>> A;
      while (j < m and a[i][0] == a[j][0]) {
         A.push_back({a[j][1], a[j][2]});
         ++j;
      }
      array<int, 2> best = {0, 0};
      for (auto &[x, y] : A) {
         best = max(best, st.query(x, y));
      }
      ++best[0];
      dp[a[i][0]] = best;
      best[1] = a[i][0];
      for (auto &[x, y] : A) {
         st.update(x, y, best);
      }
   }
   array<int, 2> best = {0, 0};
   int idx = 0;
   for (int i = 1; i <= n; ++i) {
      if (dp[i] > best) {
         best = dp[i];
         idx = i;
      }
   }
   cout << n - best[0] << '\n';
   vector<int> mark(n + 1);
   while (idx) {
      mark[idx] = 1;
      idx = dp[idx][1];
   }
   for (int i = 1; i <= n; ++i) {
      if (!mark[i]) cout << i << ' ';
   }
   cout << '\n';
   return 0;
}



// a + k * b <= d * k * r
// k * b - d * k * r <= -a
// d * k * r - k * b > a
// k > a / (d * r - b)