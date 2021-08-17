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
const int MOD = 998244353, N = 1e5 + 10; 

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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<array<int, 3>> a(n);
   map<int, int> mp;
   map<int, bool> valid;
   map<int, int> state, nxt;
   mp[0];
   vector<array<int, 2>> rng;
   for (auto &[x, y, z] : a) {
      cin >> x >> y >> z;
      valid[x] = true;
      state[x] = z;
      nxt[x] = y;
      mp[x];
      mp[y];
      rng.push_back({y, x});
   }
   mp[a.back()[0] + 1];
   vector<int> A, st, nx;
   int ctr = 0;
   for (auto &e : mp) {
      e.second = ctr++;
      A.push_back(e.first);
      if (valid[e.first]) {
         st.push_back(state[e.first]);
         nx.push_back(mp[nxt[e.first]]);
      } else {
         nx.push_back(-1);
         st.push_back(-1);
      }
   }
   int ans = 0;
   int sz = A.size();
   sort(all(rng));
   vector<int> one;
   for (auto &[x, y, z] : a) {
      if (z == 1) {
         one.push_back(x);
      }
   }
   SegTreeSum<int> tree(one.size());
   reverse(all(rng));
   int onsz = one.size();
   set<int> to_remove;
   for (int i = 0; i + 1 < sz; ++i) {
      while (!to_remove.empty() and *to_remove.begin() <= rng.back()[0]) {
         auto k = lower_bound(all(one), *to_remove.begin()) - one.begin();
         tree.update(k, onsz - 1, -1);
         to_remove.erase(to_remove.begin());
      }
      while (!rng.empty() and rng.back()[0] <= A[i]) {
         auto k = lower_bound(all(one), rng.back()[1]) - one.begin();
         tree.update(k, onsz - 1, 1);
         debug(rng.back());
         to_remove.insert(rng.back()[1]);
         rng.pop_back();
      }
      int k = lower_bound(all(one), A[i + 1]) - one.begin();
      ans += (A[i + 1] - A[i]) * (1 + tree.query(k, onsz - 1));
      ans %= MOD;
      debug(A[i], A[i + 1], ans);
   }

   cout << ans << '\n';
   return 0;
}