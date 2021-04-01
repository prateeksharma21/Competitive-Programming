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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,k;
   cin >> n >> k;
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   int l = 1, r = 1e9+10;

   auto check = [&](int v){
      int c = 0, sz = 0;
      f(i,0,n){
         if(c){
            sz++;
            c ^= 1;
         }else{
            if(a[i] <= v){
               sz++;
               c ^= 1;
            }
         }
      }
      debug(sz);
      int szz;
      c = 1,szz = 0;
      f(i,0,n){
         if(c){
            szz++;
            c ^= 1;
         }else{
            if(a[i] <= v){
               szz++;
               c ^= 1;
            }
         }  
      }
      debug(szz);
      return szz>=k or sz>=k;
   };

   int ans;

   while(l <= r){
      int m = (l+r)/2;
      debug(l,r,m);
      if(check(m)){
         ans = m;
         r = m-1;
      }else{
         l = m+1;
      }
   }
   // ans = 10;

   // int flag = false;
   // f(i,0,n){
   //    flag |= (a[i] == ans);
   // }
   // assert(flag);

   cout << ans << '\n';
   return 0;
}