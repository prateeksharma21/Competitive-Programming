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
   vector<int> a(n), b(n);
   int sum = 0;
   for (int &i : a) cin >> i, sum += i;
   for (int &i : b) cin >> i, sum -= i;
   if (sum != 0) {
      cout << -1 << '\n';
      return;
   }
   vector<int> inc, dec;
   for (int i = 0; i < n; ++i) {
      int diff = b[i] - a[i];
      if (diff > 0) while(diff--) dec.push_back(i + 1);
      else if (diff < 0) while(diff++) inc.push_back(i + 1);
   }
   cout << inc.size() << '\n';
   for (int i = 0; i < inc.size(); ++i) {
      cout << inc[i] << ' ' << dec[i] << '\n';
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