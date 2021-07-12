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

vector<int> ans;

void test(){
   int n;
   cin >> n;
   cout << upper_bound(all(ans), n) - ans.begin() << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   for (int i = 1; i <= 9; ++i) {
      int cur = 0;
      for (int j = 0; j < 11; ++j) {
         cur = cur * 10 + i;
         ans.push_back(cur);
      }
   }
   sort(all(ans));
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}