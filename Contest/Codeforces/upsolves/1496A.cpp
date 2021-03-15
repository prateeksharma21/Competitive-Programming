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
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   int c = 0;
   int l = 0, r = n - 1;
   while (l < r and s[l] == s[r]) {
      ++l, --r;
      c++;
   }
   if (c < k) {
      cout << "NO\n";
   }else if (c > k) {
      cout << "YES\n";
   } else if (l <= r){
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