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
const int MOD = 1e9+7, N = 5e5 + 10;

void test(){
   int n;
   cin >> n;
   string s;
   cin >> s;
   int a = 0;
   int b = 0;
   vector<array<int, 2>> pos(n);
   for (int i = 0; i < n; ++i) {
      a += s[i] == 'D';
      b += s[i] != 'D';
      int gc = gcd(a, b);
      pos[i] = {a / gc, b / gc};
   }
   map<array<int, 2>, int> cnt;
   for (int i = 0; i < n; ++i) {
      cnt[pos[i]]++;
      cout << cnt[pos[i]] << ' ';
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