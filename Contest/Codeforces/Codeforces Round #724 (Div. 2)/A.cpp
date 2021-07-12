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
   map<int, bool> cnt;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[a[i]] = true;
   }
   sort(all(a));
   for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a.size(); ++j) {
         if (j == i) continue;
         if (!cnt[abs(a[i] - a[j])]) {
            a.push_back(abs(a[i] - a[j]));
            cnt[a.back()] = true;
         }
         if (a.size() > 300) {
            cout << "NO\n";
            return;
         }
      }
   }
   cout << "YES\n";
   cout << a.size() << '\n';
   for (int i : a) {
      cout << i << ' ';
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