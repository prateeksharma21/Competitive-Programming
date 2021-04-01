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

vector<int> P;

void test(){
   int n;
   cin >> n;
   cout << (upper_bound(all(P), n) - begin(P)) << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   int n = 3;
   const int INF = 3e9;
   while (n * n <= 3e9) {
      P.push_back(max({(n * n - 1) / 2, 1 + (n * n - 1) / 2, n}));
      n += 2;
   }
   sort(all(P));
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}