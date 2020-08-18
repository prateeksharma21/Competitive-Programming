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
   string a,b;
   cin >> a >> b;
   f(i,0,n){
      if(a[i] > b[i]){
         cout << "-1\n";
         return;
      }
   }
   int mv = 0;
   f(i,0,20){
      char mn = 'z';
      f(j,0,n){
         if(a[j] == i+'a' and a[j]!=b[j]){
            mn = min(mn,b[j]);
         }
      }
      debug(mn);
      if(mn != 'z'){
         mv ++;
         f(j,0,n){
            if(a[j] == i+'a' and a[j]!=b[j]){
               a[j] = mn;
            }
         }
      }
   }
   cout << mv << '\n';
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
