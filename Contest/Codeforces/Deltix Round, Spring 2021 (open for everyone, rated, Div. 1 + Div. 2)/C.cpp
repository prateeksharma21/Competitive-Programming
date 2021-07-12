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
   vector<string> g[n + 1];
   g[1] = {""};
   vector<string> res;
   string prv = "";
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      int v = a[i];
      if (v == 1) {
         string k = prv + "." + to_string(v);
         g[1].push_back(k);
         prv = k;
         res.push_back(k);
         continue;
      }
      string bk = g[v - 1].back();
      g[v - 1].pop_back();
      while(bk.back() != '.') bk.pop_back();
      g[v].push_back(bk + to_string(v));
      res.push_back(g[v].back());
      prv = g[v].back();
   }
   for (string s: res) {
      cout << s.substr(1) << '\n';
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