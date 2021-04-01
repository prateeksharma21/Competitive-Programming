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
   int n,k;
   cin >> n >> k;
   vector<pair<int, int>> C(n);
   for(int i = 0; i < n; ++i){
      cin >> C[i].F;
   }
   for(int i = 0; i < n; ++i){
      cin >> C[i].S;
   }
   sort(all(C));
   vector<int> A;
   for(int i = 0; i < n; ++i){
      A.push_back(C[i].F);
   }
   // debug(A);
   vector<int> pre(n+2);
   for(int i = n-1; i >= 0; --i){
      auto pt = upper_bound(all(A),A[i]+k)-A.begin();
      // debug(pt);
      pt -= i;
      // pre[i] = pt;
      pre[i] = max(pre[i+1],int(pt));
   }
   // debug(pre);
   int ans = 0;
   for(int i = 0; i < n; ++i){
      auto pt = upper_bound(all(A),A[i]+k)-A.begin();
      ans = max(ans,pt-i+pre[pt]);
   }
   // debug(pre);
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
