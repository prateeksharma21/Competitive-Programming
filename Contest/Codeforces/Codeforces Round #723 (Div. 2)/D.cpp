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

vector<char> rev = {'A', 'N', 'T', 'O'};

vector<int> process() {
   string s;
   cin >> s;
   int n = s.length();
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      if (s[i] == 'A') {
         a[i] = 0;
      } else if (s[i] == 'N') {
         a[i] = 1;
      } else if (s[i] == 'T') {
         a[i] = 2;
      } else {
         a[i] = 3;
      }
   }
   return a;
}

void test(){
   vector<int> a = process();
   int n = a.size();
   vector<int> c(4);
   for (int i = 0; i < n; ++i) {
      c[a[i]]++;
   }
   vector<int> res;
   vector<int> fnd = {0, 1, 2, 3};
   int cur_v = -1;
   
   auto value = [&](vector<int> b) {
      SegTreeSum<int> st(n);
      vector<vector<int>> pos(3 + 1);
      for (int i = 0; i < n; ++i) {
         pos[b[i]].push_back(i);
      }
      for (int i = 0; i < 4; ++i) reverse(all(pos[i]));
      int ans = 0;
      for (int i = 0; i < n; ++i) {
         int v = a[i];
         int idx = pos[v].back();
         int app = st.query(idx, n);
         int idx_n = idx + app;
         assert(idx_n >= i);
         ans += idx_n - i;
         st.update(idx, 1);
         pos[v].pop_back();
      }
      return ans;
   };

   do {
      vector<int> b(n);
      int i = 0;
      vector<int> cn = c;
      for (int x : fnd) {
         while (cn[x]--) {
            b[i++] = x;
         }
      }
      int val_b = value(b);
      if (val_b > cur_v) {
         cur_v = val_b;
         res = b;
      }
   } while (next_permutation(all(fnd)));
   for (int i : res) {
      cout << rev[i];
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
      test();
   }
   return 0;
}