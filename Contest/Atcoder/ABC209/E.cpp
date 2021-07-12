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
const int MOD = 1e9+7, N = 1e6 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   map<string, int> mp;
   vector<char> v;
   for (int i = 0; i < 26; ++i) {
      v.push_back(i + 'a');
      v.push_back(i + 'A');
   }
   random_shuffle(all(v));
   for (char i : v) {
      for (char j : v) {
         for (char k : v) {
            string s;
            s += i;
            s += j;
            s += k;
            mp[s];
         }
      }
   }
   int c = 0;
   for (auto &e : mp) {
      e.second = c++;
   }
   vector<vector<int>> g(N);
   int n;
   cin >> n;
   vector<string> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
      int l = s[i].length();
      string f = s[i].substr(0, 3);
      string b = s[i].substr(l - 3 + 1);
      g[mp[f]].push_back(mp[b]);
   }
   return 0;
}