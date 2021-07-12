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

void Solve() {
   int n, c;
   cin >> n >> c;
   vector<array<int, 2>> a(n);
   map<int, int> mp;
   vector<array<int, 2>> v;
   for (auto &[l, r] : a) {
      cin >> l >> r;
      mp[l];
      mp[r];
      mp[l + 1];
      mp[r + 1];
      mp[l - 1];
      mp[r - 1];
      v.push_back({l, 1});
      v.push_back({r, 0});
   }
   // debug('1');
   int ctr = 0;
   for (auto &e : mp) {
      e.second = ctr++;
   }
   SegTreeSum<int> st(ctr + 2);
   sort(all(v));
   int cur = 0;
   vector<int> prv;
   vector<array<int, 2>> val;
   // debug(v);
   for (auto [x, ty] : v) {
      if (ty) {
         ++cur;
         prv.push_back(x);
      } else {
         int pos = mp[x];
         int lst = prv.back();
         prv.pop_back();
         // debug(x, lst);
         int rev = mp[lst];
         int g = st.query(rev, pos);
         int va = max(0LL, x - lst - 1 - g);
         val.push_back({cur, va});
         st.update(mp[x - 1], va);
         --cur;
      }
   }
   // debug(val);
   sort(all(val), greater{});
   // debug(val);
   int ans = n;
   for (auto [x, y] : val) {
      if (c <= y) {
         ans += x * c;
         c = 0;
         break;
      } else {
         ans += x * y;
         c -= y;
      }
   }
   cout << ans << '\n';
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