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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

void test(){
   int n;
   cin >> n;
   // n = getRand(1, 200000);
   vector<int> a(n);
   int g = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      // a[i] = getRand(1, 1000000);
      g = gcd(g, a[i]);
   }
   for (int &i : a) i /= g;
   int ans = 0;
   auto check = [&]() {
      int c = 0;
      for (int i = 0; i < n; ++i) {
         if (a[i] == 1) ++c;
      }
      return c > 0;
   };
   while (!check()) {
      ++ans;
      vector<int> b(n);
      for (int i = 0; i < n; ++i) {
         b[i] = gcd(a[i], a[(i + 1) % n]);
      }
      b.swap(a);
   }

   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 100;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}