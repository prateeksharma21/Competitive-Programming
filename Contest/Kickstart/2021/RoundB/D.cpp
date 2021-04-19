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

template <typename T>
class SegTree{
public:
   vector<T> t, A;
   int n;

   SegTree (int n) {
      this->n = n;
      this->t.assign(4 * n + 10, 0);
   }

   SegTree (vector<T> a) : SegTree (a.size()) {
      this->A = a;
      build (1, 0, n - 1);
   }

   T op (T a,T b){
      return gcd(a, b);
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

   void update (int v, int tl, int tr, int pos, T addend) {
      if (tl == tr) {
        t[v] = addend;
      } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos, addend);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, addend);
        }
        t[v] = op (t[v << 1], t[v << 1 | 1]);
      }
   }

   T query (int v, int tl, int tr, int l, int r) {
      if (l > r) {
         return 0;
      }
      if (l == tl && tr == r)
        return t[v];
      int tm = (tl + tr) / 2;
      return op (query (v << 1, tl, tm, l, min(r, tm)), 
                query (v << 1 | 1, tm+1, tr, max(l, tm+1), r));
   }

   void update (int i, T val) {
      update (1, 0, n - 1, i, val);
   }

   T query (int l,int r) {
      return query (1, 0, n-1, l, r);
   }

   T query (int i) {
      return query (i, i);
   }
};

void Solve() {
   int n, q;
   cin >> n >> q;
   vector<vector<int>> g(n);
   map<array<int, 2>, int> L, A;
   vector<int> k;
   for (int i = 0; i + 1 < n; ++i) {
      int x, y, l, a;
      cin >> x >> y >> l >> a;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
      L[{x, y}] = L[{y, x}] = l;
      A[{x, y}] = A[{y, x}] = a;
      k.push_back(l);
   }
   sort(all(k));
   map<int, int> pos;
   for (int i = 0; i < n - 1; ++i) {
      pos[k[i]] = i;
   }

   vector<vector<array<int, 2>>> city(n);
   
   for (int i = 0; i < q; ++i){
      int c, w;
      cin >> c >> w;
      --c;
      city[c].push_back({w, i});
   }


   SegTree<int> st(n - 1);
   vector<int> ans(q);

   function<void(int, int)> dfs = [&](int u, int p) {
      if (u != p) {
         int ps = pos[L[{u, p}]];
         int v = A[{u, p}];
         st.update(ps, v);
      }

      for (auto [w, i] : city[u]) {
         int p = upper_bound(all(k), w) - k.begin();
         if (p == 0) {
            ans[i] = 0;
         } else {
            ans[i] = st.query(0, p - 1);
         }
      }

      for (int v : g[u]) {
         if (v == p) continue;
         dfs(v, u);
      }

      if (u != p) {
         int ps = pos[L[{u, p}]];
         st.update(ps, 0);
      }
   };

   dfs(0, 0);

   for (int i = 0; i < q; ++i) {
      cout << ans[i] << ' ';
   }
   cout << '\n';

   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}