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
   map<int, int> cnt;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x]++;
   }
   multiset<int> s;
   for (auto &e : cnt) s.insert(e.second);

   while (s.size() > 1) {
      int a = *prev(s.end());
      s.erase(prev(s.end()));
      int b = *prev(s.end());
      s.erase(prev(s.end()));
      --a, --b;
      if (a != 0) s.insert(a);
      if (b != 0) s.insert(b);
   }
   if (s.empty()) {
      cout << 0 << '\n';
      return;
   }
   cout << *s.begin() << '\n';
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