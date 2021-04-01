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
const int MOD = 1e9+7, N = 1e6 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> a(n+1);
   f(i,1,n+1){
      cin >> a[i];
   }
   f(i,0,1000*N);
   vector<int> pos;
   vector<int> r(n+1);
   int mn = 0;
   f(i,1,n+1){
      pos.pb(i);
      int v = a[i]-mn;
      while(v--){
         auto k = pos.back();
         pos.pop_back();
         r[k] = mn++;
      }
   }
   int MX = 1e6;
   while(!pos.empty()){
      r[pos.back()] = MX--;
      pos.pop_back();
   }
   f(i,1,n+1){
      cout << r[i] << ' ';
   }
   cout << '\n';
   return 0;
}