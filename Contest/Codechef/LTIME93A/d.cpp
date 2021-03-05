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
   int n, m;
   cin >> n >> m;
   vector<vector<int>> g(n + 1);
   vector<int> deg(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
      ++deg[u], ++deg[v];
   }
   string ans(n, '0');
   int w = 0;
   set<int> rem;
   for (int i = 1; i <= n; ++i) {
      rem.insert(i);
   }   
   for (int u = 1; u <= n; ++u) {
      if (!rem.count(u)) continue;
      map<int, int> done;
      vector<int> removed;
      for (int v : g[u]) {
         if (rem.count(v)) {
            rem.erase(v);
            removed.push_back(v);
         }
      }
      vector<int> candidate;
      for (int v : rem) {
         done[v] = 1;
         candidate.push_back(v);
      }
      debug(candidate);
      rem.clear();
      for (int i  : removed) rem.insert(i);
      int sz = candidate.size();
      int bad = 0;
      for (int v : candidate) {
         for (int k : g[v]) {
            if (done[k]) {
               bad = 1;
               break;
            }
         }
         if (bad) break;
      }
      if (bad) continue;
      for (int i : candidate) {
         if (deg[i] != n - sz) {
            bad = 1;
            break;
         }
      }
      if (bad) continue;
      ++w;
      string res(n, '0');
      for (int j : candidate) {
         done[j] = 1;
         res[j - 1] = '1';
      }
      ans = res;
   }
   cout << w << '\n' << ans << '\n';
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