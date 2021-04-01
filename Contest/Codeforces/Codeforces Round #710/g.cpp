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
   string s;
   cin >> s;
   int n = s.length();
   vector<int> vis(26);
   for (int i = 0; i < n; ++i) {
      vis[s[i] - 'a'] = 1;
   }

   vector<int> K;
   for (int i = 0; i < 26; ++i) {
      if (vis[i]) K.push_back(i);
   }

   reverse(all(K));

   int l = -1;

   auto can = [&](int v) {
      vector<int> k = vis;
      int sm = accumulate(all(k), 0LL);
      int pos = -1;
      // debug(sm);
      for (int i = n - 1; i > l; --i) {
         if (k[s[i] - 'a']) {
            k[s[i] - 'a'] ^= 1;
            --sm;
         }
         if (sm == 0 and s[i] == v + 'a') {
            pos = i;
         }
      }
      if (pos == -1) return false;
      l = pos;
      return true;
   };

   // debug('1');

   while (!K.empty()) {
      int choosen = -1;
      // debug(K);
      for (int i : K) {
         if (can(i)) {
            choosen = i;
            break;
         }
      }
      assert(choosen != -1);
      vis[choosen] ^= 1;
      vector<int> nK;
      for (int i : K) {
         if (i != choosen) {
            nK.push_back(i);
         }   
      }
      K = nK;
      cout << char(choosen + 'a');
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