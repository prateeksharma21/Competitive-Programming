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
   int n,x,y;
   cin >> n >> x >> y;
   vector<int> F;
   int d = y-x;
   for(int i = 1; i <= d; ++i){
      if(d % i == 0){
         F.push_back(i);
      }
   }
   debug(F);
   int MX = 1e18, st, en, val;
   for(int v : F){
      int compulsary = d/v+1;
      // debug(compulsary);
      if(compulsary > n){
         continue;
      }
      int rem = n-compulsary;
      int c = x-v;
      int req = 0;
      int l = x;
      for(int i = 0; i < rem; ++i){
         if(c > 0){
            req++;
            l = c;
            c -= v;
         }
      }
      rem -= req;
      int mx = y;
      c = y;
      while(rem > 0){
         rem--;
         c += v;
         mx = c;
      }
      debug(mx);
      if(MX > mx){
         MX = mx;
         val = v;
         st = l, en = mx;
      }
   }
   // debug(st,en,val,MX);
   for(int i = st; i <= en; i += val){
      cout << i << ' '; 
   }
   cout << '\n';
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
 