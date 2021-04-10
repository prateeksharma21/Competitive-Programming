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

void Solve() {
   int n, q;
   cin >> n >> q;

   vector<array<int, 2>> a(n);   

   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s >> a[i][1];
      int v = 0;
      for (int i = 0; i < q; ++i) {
         if (s[i] == 'T') {
            v |= (1 << i);
         }
      }
      a[i][0] = v;
   }

   vector<int> all;

   auto valid = [&](int t) {
      for (int i = 0; i < n; ++i) {
         int v = 0;
         for (int j = 0; j < q; ++j) {
            v += ((a[i][0] >> j & 1) == (t >> j & 1));
         }
         if (v != a[i][0]) return false;
      }
      return true;
   };

   function<void(int, string)> solve = [&](int x, string s) {
      if (x == q) {
         if (valid(s)) {
            all.push_back(s);
         }
         return;
      }
      s += "T";
      solve(x + 1, s);
      s.pop_back();
      s += "F";
      solve(x + 1, s);
   };

   solve(0, "");

   int mx = 0;
   string ans;

   auto score = [&](string &t) {
      int v = 0;
      for (int i = 0; i < all.size(); ++i) {
         for (int j = 0; j < q; ++j) {
            v += (all[i][j] == t[j]);
         }
      }
      return v;
   };

   function<void(int, string)> solve1 = [&](int x, string s) {
      if (x == q) {
         int sc = score(s);
         if (sc > mx) {
            mx = sc;
            ans = s;
         }
         return;
      }
      s += "T";
      solve1(x + 1, s);
      s.pop_back();
      s += "F";
      solve1(x + 1, s);
   };   

   solve1(0, "");   

   int sz = all.size();

   int g = gcd(mx, sz);

   mx /= g;
   sz /= g;

   cout << ans << ' ' << mx << '/' << sz << '\n';
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