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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<array<int, 4>> a(n);

   auto get_point = [&](int a, int b, int c, int d) {
      {
         int g = gcd(a, b);
         a /= g;
         b /= g;
      }
      {
         int g = gcd(c, d);
         c /= g;
         d /= g;
      }
      int num = gcd(a * d, b * c);
      int den = (b * d);
      int g = gcd(num, den);
      num /= g, den /= g;
      a *= den, b *= num;
      c *= den, d *= num;
      {
         int g = gcd(a, b);
         a /= g;
         b /= g;
      }
      {
         int g = gcd(c, d);
         c /= g;
         d /= g;
      }
      array<int, 4> r = {a, b, c, d};
      return r;
   };

   map<array<int, 4>, vector<int>> ind; 

   vector<array<int, 4>> pt;
   for (int i = 0, a, b, c, d; i < n; ++i) {
      cin >> a >> b >> c >> d;
      pt.push_back({a, b, c, d});
   }

   debug(pt);

   set<int> cur;

   for (int i = 0; i < n; ++i) {
      cur.insert(i);
      debug(i);
      auto [a, b, c, d] = pt[i];
      {
         array<int, 4> T = get_point(a + b, b, c, d);
         debug(T);
         ind[T].push_back(i);
      }
      {
         array<int, 4> T = get_point(a, b, c + d, d);
         debug(T);
         ind[T].push_back(i);
      }
   }

   vector<array<int, 2>> ans;

   for (auto [_, v] : ind) {
      int sz = v.size();
      for (int i = 0; i + 1 < n; ) {
         if (cur.count(v[i]) and cur.count(v[i + 1])) {
            cur.erase(v[i]);
            cur.erase(v[i + 1]);
            ans.push_back({v[i], v[i + 1]});
            i += 2;
         } else {
            ++i;
         }
      }
   }

   cout << ans.size() << '\n';
   for (auto [a, b] : ans) {
      cout << a + 1 << ' ' << b + 1 << '\n';
   }
   return 0;
}