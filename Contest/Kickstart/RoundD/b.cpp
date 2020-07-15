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
   vector<int> a(n);
   int ans = 0;
   int prv = -1;
   f(i,0,n){
      cin >> a[i];
   }
   int inc = 1,dcr = 1;
   f(i,1,n){
      if(a[i] == a[i-1]){
         continue;
      }
      if(a[i] > a[i-1]){
         inc++;
         dcr = 1;
      }else{
         dcr++;
         inc = 1;
      }
      if(inc > 4 or dcr > 4){
         ans++;
         inc = 1;
         dcr = 1;
      }
      debug(ans);
   }
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt){
      cout << "Case #" << i+1 << ": ";
      test();   
   }
   return 0;
}