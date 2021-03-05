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
   int p,f;
   cin >> p >> f;
   int n,m,s,w;
   cin >> n >> m >> s >> w;
   int ans = 0;
   for(int i = 0; i <= n; ++i){
      int ff = i*s;
      if(ff > p) break;
      int rem = p-ff;
      int j = rem/w;
      j = min(j,m);
      int tot = i+j;
      int sr = n-i, wr = m-j;
      if(s <= w){
         int ri = min(f/s,sr);
         int rem = f-ri*s;
         int rj = min(rem/w,wr);
         tot += (ri+rj);
      }else{
         int rj = min(f/w,wr);
         int rem = f-rj*w;
         int ri = min(rem/s,sr);
         tot += (ri+rj);
      }
      ans = max(ans,tot);
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
