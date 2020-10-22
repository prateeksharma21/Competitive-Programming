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

int get(int x){
   if(x >= 0){
      return (x+1)/2;
   }else{
      return x/2;
   }
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> A(n+1);
   vector<int> diff(n+1);
   for(int i = 1; i <= n; ++i){
      cin >> A[i];
   }
   int inc = 0;
   for(int i = 2; i <= n; ++i){
      diff[i] = A[i]-A[i-1];
      if(A[i] > A[i-1]){
         inc += diff[i];
      }
   }
   cout << get(A[1]+inc) << '\n';
   int q;
   cin >> q;
   while(q--){
      int l,r,x;
      cin >> l >> r >> x;
      if(l == 1){
         A[1] += x;
      }
      if(l > 1){
         if(diff[l] > 0) inc -= diff[l];
         diff[l] += x;
         if(diff[l] > 0) inc += diff[l];
      }
      if(r < n){
         if(diff[r+1] > 0) inc -= diff[r+1];
         diff[r+1] -= x;
         if(diff[r+1] > 0) inc += diff[r+1];
      }
      cout << get(A[1]+inc) << '\n';
   }
   return 0;
}