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
   int n;
   cin >> n;
   vector<int> o,e;
   f(i,0,2*n){
      int x;
      cin >> x;
      if(x & 1) o.pb(i+1);
      else e.pb(i+1);
   }
   int sz = o.size();
   debug(sz);
   if(sz % 2 == 0){      
      if(!o.empty()){
         f(i,0,sz-2){
            cout << o[i] << ' ' << o[i+1] << '\n';
            i++;
         }
         f(i,0,(int)e.size()){
            cout << e[i] << ' ' << e[i+1] << '\n';
            i++;
         }
      }else{
         sz = e.size();
         f(i,0,sz-2){
            cout << e[i] << ' ' << e[i+1] << '\n';
            i++;
         }
         f(i,0,(int)o.size()){
            cout << o[i] << ' ' << o[i+1] << '\n';
            i++;
         }
      }
      return;
   }
   f(i,0,sz-1){
      cout << o[i] << ' ' << o[i+1] << '\n';
      i++;
   }
   sz = e.size();
   f(i,0,sz-1){
      cout << e[i] << ' ' << e[i+1] << '\n';
      i++;
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
