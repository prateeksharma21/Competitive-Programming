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
const int MOD = 1e9+7, N = 1e3 + 10;

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

int n, q, p;
int val[N][5];

void process() {
   for (int i = 1; i < N; ++i) {
      int cur = i;
      int md = i % p;
      for (int j = 1; j <= 4; ++j) {
         int k = cur - md;
         if (k == 0) {
            val[i][j] = k;
            continue;
         }
         int cnt = 0;
         while (k % p == 0) {
            k /= p;
            ++cnt;
         }
         val[i][j] = cnt;
         cur *= i;
         md *= (i % p);
      }
   }
}

void test(){
   cin >> n >> q >> p;
   process();
   vector<int> a(n);
   for (int &i : a) cin >> i;


   SegTreeSum<int> st1(n), st2(n), st3(n), st4(n);
   for (int i = 0; i < n; ++i) {
      st1.update(i, val[a[i]][1]);
      st2.update(i, val[a[i]][2]);
      st3.update(i, val[a[i]][3]);
      st4.update(i, val[a[i]][4]);
   }


   while (q--) {
      int ty;
      cin >> ty;
      if (ty == 1) {
         int i, va;
         cin >> i >> va;
         --i;
         st1.update(i, -val[a[i]][1]);
         st2.update(i, -val[a[i]][2]);
         st3.update(i, -val[a[i]][3]);
         st4.update(i, -val[a[i]][4]);
         a[i] = va;
         st1.update(i, val[a[i]][1]);
         st2.update(i, val[a[i]][2]);
         st3.update(i, val[a[i]][3]);
         st4.update(i, val[a[i]][4]);
         continue;
      }
      int s, l, r;
      cin >> s >> l >> r;
      --l, --r;
      if (s == 1) {
         cout << st1.query(l, r);
      } else if (s == 2) {
         cout << st2.query(l, r);
      } else if (s == 3) {
         cout << st3.query(l, r);
      } else {
         cout << st4.query(l, r);
      }
      cout << ' ';
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
      test();
   }
   return 0;
}