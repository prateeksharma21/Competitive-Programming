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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   set<int> mex;
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mex.insert(i);
   }   
   mex.insert(n);
   map<int, int> cnt;
   for (int i = 0; i < m; ++i) {
      if (mex.count(a[i])) {
         mex.erase(a[i]);
      }
      ++cnt[a[i]];
   }
   int ans = *mex.begin();
   for (int i = m; i < n; ++i) {
      // remove 
      --cnt[a[i - m]];
      if (cnt[a[i - m]] == 0) {
         mex.insert(a[i - m]);
      }

      if (mex.count(a[i])) {
         mex.erase(a[i]);
      }
      ++cnt[a[i]];
      ans = min(ans, (int)*mex.begin());
   }
   cout << ans;
   return 0;
}