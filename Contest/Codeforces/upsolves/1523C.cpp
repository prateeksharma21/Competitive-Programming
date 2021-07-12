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
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<int> stk;
   for (int i = 0; i < n; ++i) {
      if (a[i] > 1) {
         while (stk.back() != a[i] - 1) stk.pop_back();
         stk.pop_back();
      }
      stk.push_back(a[i]);
      int sz = stk.size();
      for (int j = 0; j < sz; ++j) {
         cout << stk[j] << ".\n"[j == sz - 1];
      }
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