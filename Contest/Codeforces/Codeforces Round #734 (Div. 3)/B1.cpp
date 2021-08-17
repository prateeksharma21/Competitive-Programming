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
   string s;
   cin >> s;
   n = s.length();
   k = 2;
   vector<int> a(n);
   vector<int> cnt(300);
   vector<array<int, 2>> b(n);
   for (int i = 0; i < n; ++i) {
      a[i] = s[i];
      cnt[a[i]]++;
      b[i] = {a[i], i};
   }
   debug(a);
   int mx = *max_element(all(cnt));
   int ans = k;
   vector<int> cur(300);
   sort(all(b));
   vector<int> res(n, -1);
   int tmp = 0;
   int done = 0;
   for (auto [v, i] : b) {
      if (cur[v] < ans) {
         cur[v]++;
         ++done;
         res[i] = tmp++;
      }
      tmp %= ans;
   }
   int rem = done % ans;
   debug(rem);
   for (auto [v, i] : b) {
      if (res[i] >= 0 and rem) {
         --rem;
         res[i] = -1;
      }
   }
   cout << count(all(res), 1) << '\n';
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