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
const int MOD = 1e9+7, N = 2e5 + 10; 
const int M = 31;

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

   T query (int v, int tl, int tr, int val) {
      push (v, tl, tr);
      int tm = (tl + tr) / 2;
      if (tl == tr) return tl;
      push (2 * v, tl, tm);
      push (2 * v + 1, tm + 1, tr);
      if (val > t[2 * v]) {
         return query(v << 1 | 1, tm + 1, tr, val - 2 * t[v << 1]);
      }
      return query(v << 1, tl, tm, val);
   }

   T query (int val) {
      return query (1, 0, n - 1, val);
   }

   void update (int l, int r, T val) {
      update (1, 0, n - 1, l, r, val);
   }

   void update (int p, T val) {
      update (1, 0, n - 1, p, p, val);
   }
};

int query(int l, int r) {
   cout << "? " << l << ' ' << r << endl;
   int sum;
   cin >> sum;
   int n = r - l + 1;
   int z = n - sum;
   return z;
}

int n, t;
vector<array<int, 2>> blk;
int blk_sz;
SegTreeSum<int> st(N);
bool _init;

void init() {
   for (int i = 1; i <= n; i += M) {
      blk.push_back({i, min(i + M - 1, n)});
   }
   blk_sz = blk.size();
   for (int i = 0; i < blk_sz; ++i) {
      int v = query(blk[i][0], blk[i][1]);
      st.update(i, v);
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> t;
   while (t--) {
      int k;
      cin >> k;
      if (!_init) {
         _init = true;
         init();
      }
      int l = 0, r = blk_sz - 1;
      int ans = st.query(k);
      l = blk[ans][0], r = blk[ans][1];
      st.update(ans, -1);
      while (l <= r) {
         int m = (l + r) / 2;
         if (query(1, m) >= k) {
            ans = m;
            r = m - 1;
         } else {
            l = m + 1;
         }
      }
      cout << "! " << ans << endl;
   }
   return 0;
}