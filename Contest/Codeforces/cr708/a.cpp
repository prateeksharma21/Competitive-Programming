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
   vector<int> cnt(101);
   for (int &i : a) {
      cin >> i;
      cnt[i]++;
   }
   for (int i = 0; i < 101; ++i) {
      if (cnt[i]) {
         cout << i << ' ';
         --cnt[i];
      } else {
         break;
      }
   }
   for (int i = 0; i < 101; ++i) {
      while (cnt[i]) {
         cout << i << ' ';
         --cnt[i];
      }
   }
   cout << '\n';
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