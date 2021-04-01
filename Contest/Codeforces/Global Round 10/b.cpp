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
   vector<int> a(n);
   int mx = -1e15;
   int mn = 1e15;
   for(int i = 0; i < n; ++i){
      cin >> a[i];
      mx = max(mx,a[i]);
      mn = min(mn,a[i]);
   } 
   if(k & 1){
      for(int i = 0; i < n; ++i){
         cout << mx-a[i] << ' ';
      }
   }else{
      for(int i = 0; i < n; ++i){
         cout << a[i]-mn << ' ';
      }
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
