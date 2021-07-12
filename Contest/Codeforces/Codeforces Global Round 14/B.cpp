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

bool square(int x) {
   int sq = sqrt(x);
   return sq * sq == x;
}

void test(){
   int n;
   cin >> n;
   if (n % 2 == 0 and square(n / 2)) {
      cout << "YES\n";
      return;
   }
   if (n % 4 == 0 and square(n / 4)) {
      cout << "YES\n";
      return;
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