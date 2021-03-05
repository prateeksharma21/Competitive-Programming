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

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i : a) {
      cin >> i;
   }  
   int sm = a[0];
   vector<int> K,L;
   for (int i = 1; i < n; ++i) {
      sm = a[i] - sm;
      if (i & 1){
         K.push_back(sm);
      } else {
         L.push_back(sm);
      }
   }
   if (n == 2) {
      if (a[0] == a[1]) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
      return;
   }
   vector<int> sig(n + 1);
   for (int i = n - 1; i >= 0; --i) {
      sig[i] = sig[i + 1] ^ 1;
   }
   for (int i = 0; i < n; ++i) {
      if (sig[i] == 0) sig[i] = -1;
   }
   SegTree<int, false> st1(K), st2(L);
   int szk = K.size(), szl = L.size();
   if (st1.query(0, szk - 1) >= 0 and st2.query(0, szl - 1) >= 0 and sm == 0) {
      cout << "YES\n";
      return;
   }
   int pk = 0, pl = 0;
   for (int i = 1; i < n; ++i) {
      if (i & 1) {
         int v = a[i - 1] - a[i];
         st1.update(pk, szk - 1, 2 * v);
         st2.update(pl, szl - 1, -2 * v);
         if (pl - 1 >= 0) {
            st2.update(pl - 1, a[i] - a[i - 1]);
         }
         if (st1.query(0, szk - 1) >= 0 and st2.query(0, szl - 1) >= 0 and sm + (-2 * sig[i]) * a[i] + (-2 * sig[i - 1]) * a[i - 1] == 0) {
            cout << "YES\n";
            return;
         }
         if (pl - 1 >= 0) {
            st2.update(pl - 1, a[i - 1] - a[i]);
         }
         v = -v;
         st1.update(pk, szk - 1, 2 * v);
         st2.update(pl, szl - 1, -2 * v);
         ++pk;
      } else {
         int v = a[i] - a[i - 1];
         st1.update(pk, szk - 1, 2 * v);
         st2.update(pl, szl - 1, -2 * v);
         if (pk - 1 >= 0) {
            st1.update(pk - 1, a[i] - a[i - 1]);
         }
         if (st1.query(0, szk - 1) >= 0 and st2.query(0, szl - 1) >= 0 and sm + (-2 * sig[i]) * a[i] + (-2 * sig[i - 1]) * a[i - 1] == 0) {
            cout << "YES\n";
            return;
         }
         if (pk - 1 >= 0) {
            st1.update(pk - 1, a[i - 1] - a[i]);
         }
         v = -v;
         st1.update(pk, szk - 1, 2 * v);
         st2.update(pl, szl - 1, -2 * v);
         ++pl;
      }
   }

   cout << "NO\n";
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