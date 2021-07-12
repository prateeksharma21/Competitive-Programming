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
   vector<T> t, A;
   int n;

   SegTree (int n) {
      this->n = n;
      this->t.assign(4 * n + 10, 0);
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

   void update(int v, int tl, int tr, int pos, int new_val) {
       if (tl == tr) {
           t[v] = new_val;
       } else {
           int tm = (tl + tr) / 2;
           if (pos <= tm)
               update(v*2, tl, tm, pos, new_val);
           else
               update(v*2+1, tm+1, tr, pos, new_val);
           t[v] = op(t[v*2],t[v*2+1]);
       }
   }

   T query (int v, int tl, int tr, int l, int r) {
      if (l > r) {
         if (max_mode) return -1e15;
         return 1e15;
      }
      if (l <= tl && tr <= r)
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

void test(int t){
   int n;
   cin >> n;
   vector<int> a(n + 1), b(n + 1);
   vector<vector<int>> g1(n + 1), g2(n + 1);
   for (int i = 2; i <= n; ++i) {
      cin >> a[i];
      g1[i].push_back(a[i]);
      g1[a[i]].push_back(i);
   }
   for (int i = 2; i <= n; ++i) {
      cin >> b[i];
      g2[i].push_back(b[i]);
      g2[b[i]].push_back(i);
   }

   vector<int> tin(n + 1), tout(n + 1);
   int timer = 1;

   function<void(int, int)> dfs = [&](int u, int p) {
      tin[u] = timer++;
      for (int v : g2[u]) {
         if (v == p) continue;
         dfs(v, u);
      }
      tout[u] = timer++;
   };

   dfs(1, 0);

   set<array<int, 2>> s;
   int ans = 1;
   function<void(int, int)> dfs2 = [&](int u, int p) {
      auto it = s.lower_bound({tin[u], -1});
      array<int, 2> rem = {-1, -1};
      if (it != s.begin()) {
         --it;
         auto [l, r] = *it;
         if (tin[u] > l and tout[u] < r) {
            rem = {l, r};
            s.erase(it);
            s.insert({tin[u], tout[u]});
         } else if (tin[u] > r) {
            s.insert({tin[u], tout[u]});
         } else if (tout[u] < l) {
            s.insert({tin[u], tout[u]});
         }
      } else {
         s.insert({tin[u], tout[u]});
      }
      ans = max(ans, (int)s.size());
      for (int v : g1[u]) {
         if (v == p) continue;
         dfs2(v, u);
      }
      if (s.count({tin[u], tout[u]})) {
         s.erase({tin[u], tout[u]});
      }
      if (rem[0] != -1) {
         s.insert(rem);
      }
   };

   dfs2(1, 0);

   cout << ans << '\n';

   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test(t);
   }
   return 0;
}