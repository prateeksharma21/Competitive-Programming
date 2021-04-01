#ifdef Prateek
  #include "Prateek.h"
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
   int n, m;
   cin >> n >> m;
   vector<int> k(n);
   vector<int> pre(m + 1);
   for (int &i : k) {
      cin >> i;
      pre[i] += 1;
   }
   sort(all(k));
   vector<int> c(m + 1);
   for (int i = 1; i <= m; ++i) {
      cin >> c[i];
   }
   int ans = 0;
   vector<int> cst;
   for (int i = 1; i <= m; ++i) {
      if (pre[i]) {
         for (int j = 0; j < pre[i]; ++j) {
            cst.push_back(c[i]);
         }
      }
      cst.push_back(c[i]);
      if (cst.size() > n) break;
   }
   for (int i = 0; i < n; ++i) {
      ans += cst[i];
   }
   cout << ans << '\n';
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