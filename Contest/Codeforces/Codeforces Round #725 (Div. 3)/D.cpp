#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

int get(int x) {
   int ans = 0;
   for (int i = 2; i * 1LL * i <= x; ++i) {
      while (x % i == 0) {
         x /= i;
         ++ans;
      }
   }
   ans += (x > 1);
   return ans;
}

void test(){
   int a, b, k;
   cin >> a >> b >> k;
   int g = gcd(a, b);
   a /= g;
   b /= g;
   int mn = (a > 1) + (b > 1);

   int A = get(a);
   int B = get(b);
   int G = get(g);


   if (A + B == 0) {
      if (k == 1) {
         cout << "NO\n";
         return;
      }
   }

   if (k >= mn and k <= A + B + 2 * G) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
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