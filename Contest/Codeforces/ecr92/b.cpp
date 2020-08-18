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
   int n,k,z;
   cin >> n >> k >> z;
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   int R = a[0];
   int cur = a[0];
   set<int> s;
   f(i,1,n){
      cur += a[i];
      s.insert(a[i]+a[i-1]);
      int rem = k-i;
      debug(s,rem);
      if(rem < 0) break;
      if(rem & 1){
         int dn = (rem+1)/2;
         if(dn <= z){
            int v = cur + dn*a[i-1] + (rem-dn)*a[i];
            R = max(R,v);
         }
      }else{
         int dn = rem/2;
         if(dn <= z){
            auto kk = *s.rbegin();
            int v = cur + dn*kk;
            R = max(R,v);
         }
      }
   }
   cout << R << '\n';
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
