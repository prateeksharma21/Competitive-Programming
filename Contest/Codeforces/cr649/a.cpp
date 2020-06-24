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
   int n,x;
   cin >> n >> x;
   vector<int> a(n);
   int sm = 0;
   f(i,0,n){
      cin >> a[i];
      sm += a[i];
   }
   if(sm % x != 0){
      cout << n << '\n';
      return;
   }
   int tt = sm;
   int st = -1;
   f(i,0,n){
      tt -= a[i];
      if(tt % x != 0){
         st = i;
         break;
      }
   }
   int en = n;
   tt = sm;
   for(int i = n-1;i >= 0; --i){
      tt -= a[i];
      if(tt % x != 0){
         en = i;
         break;
      }
   }
   if(st == -1 and en == n){
      cout << "-1\n";
      return;
   }
   int ans;
   if(st != -1){
      ans = n-1-st;
   }
   if(en != n){
      ans = max(ans,en);
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
