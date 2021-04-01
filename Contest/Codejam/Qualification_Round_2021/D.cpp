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
const int MOD = 1e9+7, N = 100 + 10;

int Q[N][N][N];
int n, q;

int query(int a, int b, int c) {
   vector<int> k = {a, b, c};
   sort(all(k));
   a = k[0], b = k[1], c = k[2];
   int &q = Q[a][b][c];
   if (q) return q;
   cout << a << ' ' << b << ' ' << c << endl;
   cin >> q;
   return q;
}

void Solve() {

   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         for (int k = 1; k <= n; ++k) {
            Q[i][j][k] = 0;
         }
      }
   }

   debug(1);

   int v = query(1, 2, 3);
   vector<int> a;
   if (v == 1) {
      a = {2, 1, 3};
   } else if (v == 2) {
      a = {1, 2, 3};
   } else {
      a = {1, 3, 2};
   }

   for (int i = 4; i <= n; ++i) {
      int l = 0, r = i - 2;
      while (l < r) {
         int m = (l + r) / 2;
         int v = query(a[m + 1], a[m], i);
         if (v == i) {
            a.insert(a.begin() + m + 1, i);
            break;
         }
         if (v == a[m]) {
            r = m;
         } else {
            l = m + 1;
         }
      }
      debug(a);
      while (a.size() < i) {
         if (l != 0) {
            a.push_back(i);
         } else {
            a.insert(a.begin(), i);
         }
      }
   }

   for (int i : a) {
      cout << i << ' ';
   }
   cout << endl;

   cin >> v;
   assert(v == 1);
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt >> n >> q;
   for (int t = 1; t <= tt; ++t) {
      // cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}