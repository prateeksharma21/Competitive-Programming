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
   f(i,0,n) cin >> a[i];
   reverse(all(a));
   vector<int> V(n);
   V[0] = 1;
   f(i,1,n){
      if(a[i] >= a[i-1]){
         V[i] = 1;
      }else{
         break;
      }
   }
   reverse(all(a));
   reverse(all(V));
   V.pb(1);
   int cur = 0;
   for(int i = 0, j = 0; i < n; i = j){
      int prv = a[i];
      while(j < n and a[j] >= prv){
         prv = a[j];
         j++;
      }
      if(V[j]){
         cout << cur << '\n';
         return;
      }
      cur += (j-i);
   }
   cout << n-1 << '\n';
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
