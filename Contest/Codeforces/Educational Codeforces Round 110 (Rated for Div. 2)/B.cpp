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

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   vector<int> two, oth;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] % 2) {
         oth.push_back(a[i]);
      } else {
         two.push_back(a[i]);
      }
   }
   vector<int> b;
   for (int i : two) b.push_back(i);
   for (int i : oth) b.push_back(i);
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         ans += (gcd(b[i], 2 * b[j]) > 1);
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
      test();
   }
   return 0;
}