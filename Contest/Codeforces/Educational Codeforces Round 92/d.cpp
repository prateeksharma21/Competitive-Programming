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
   int l1,l2,r1,r2;
   cin >> l1 >> r1 >> l2 >> r2;

   if(l1 > l2){
      swap(l1,l2);
      swap(r1,r2);
   }

   debug(l1,r1);
   debug(l2,r2);

   int common = max(0ll,min(r1,r2)-max(l1,l2));

   auto chk = [&](int v){
      int R = common*n;
      if(R >= k) return true;
      if(l2>r1){
         int mx = max(r1-l1,r2-l2)+1;
         int rng = l2-r1;
         v -= (rng-1);
         if(v > 0){
            if(rng == 1){
               R += min(v,mx);
               v -= min(v,mx);
               R += (v/(mx))*(mx-1);
               v %= (mx);
               R += v;
            }else{
               R += min(v,mx);
               v -= min(v,mx);
               R += (v/(mx))*(mx-1);
               v %= (mx);
               R += v;
            }
         }
      }else{
         int cl = max(l1,l2),cr = min(r1,r2);
         int l = cl-min(l1,l2), r = max(r1,r2)-cr;
         int mn = min(v,l+r);
         R += mn*n;
         v -= mn;
         R += (v/(n+1))*n;
         v %= (n+1);
         R += v*(v-1)/2;
      }
      return R >= k; 
   };

   int ans = 1e10;

   int l = 0,h = 1e10;
   while(l <= h){
      int mid = (l+h)/2;
      if(chk(mid)){
         ans = mid;
         h = mid-1;
      }else{
         l = mid+1;
      }
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
