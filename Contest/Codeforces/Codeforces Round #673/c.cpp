#ifdef Prateek
  #include "C:\Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector<int> A(n+1);
   vector<vector<int>> pos(n+1);
   for(int i = 1; i <= n; ++i) {
      cin >> A[i];
      pos[A[i]].push_back(i);
   }
   vector<int> ans(n+1, -1);
   int lst = n;
   for(int i = 1; i <= n; ++i) {
      if(pos[i].empty()) {
         continue;
      }
      int mx = max(pos[i].front(), n-pos[i].back()+1);
      for(int j = 1; j < pos[i].size(); ++j) {
         mx = max(mx, pos[i][j] - pos[i][j-1]);
      }
      for(int j = mx; j <= lst; ++j) {
         ans[j] = i;
      }
      lst = min(lst, mx-1);
   }
   for(int i = 1; i <= n; ++i) {
      cout << ans[i] << " \n"[i == n];
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
