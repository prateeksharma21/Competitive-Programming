#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

vector<int> g[N];
int deg[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m, k;
   cin >> n >> m >> k;

   vector<string> pattern(n);
   set<string> have;
   unordered_map<string, int> hsh;

   for (int i = 0; i < n; ++i) {
      cin >> pattern[i];
      hsh[pattern[i]] = i;
      have.insert(pattern[i]);
   }
   
   for (int i = 0; i < m; ++i) {
      string s;
      int val;
      cin >> s >> val;
      --val;
      bool found = false;
      for (int j = 0; j < (1 << k); ++j) {
         string ns = "";
         for (int l = 0; l < k; ++l) {
            if (j >> l & 1) {
               ns += '_';
            } else {
               ns += s[l];
            }
         }
         if (ns != pattern[val] and have.count(ns)) {
            int pos = hsh[ns];
            g[val].push_back(pos);
            ++deg[pos];
         }
         found |= (ns == pattern[val]);
      }
      if (!found) {
         cout << "NO\n";
         return 0;
      }
   }
   queue<int> q;
   vector<int> res;
   for (int i = 0; i < n; ++i) {
      if (deg[i] == 0) {
         q.push(i);
      }
   }
   while (!q.empty()) {
      auto k = q.front();
      q.pop();
      res.push_back(k);
      for (int v : g[k]) {
         --deg[v];
         if (deg[v] == 0) {
            q.push(v);
         }
      }
   }
   if (res.size() != n) {
      cout << "NO\n";
   } else {
      cout << "YES\n";
      for (int i : res) {
         cout << i + 1 << ' ';
      }
   }
   return 0;
}