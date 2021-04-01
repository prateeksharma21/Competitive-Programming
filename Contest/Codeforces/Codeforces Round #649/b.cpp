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
   vector<int> A(n+1);
   f(i,1,n+1){
      cin >> A[i];
   }
   vector<int> R = {A[1]};
   int c = 1;
   if(A[1]>A[2]){
      c = 0;
   }else if(A[1] == A[2]){
      c = 2;
   }
   int i = 3;
   while(i<=n){
      if(A[i]>A[i-1] and (c == 1 or c == 2)){
         i++;
      }else if(A[i]<A[i-1] and (c == 0 or c == 2)){
         i++;
      }else if(A[i] == A[i-1]){
         i++;
      }else{
         R.pb(A[i-1]);
         if(A[i]>A[i-1]) c = 1;
         else c = 0;
      }
   }
   R.pb(A[n]);
   cout << R.size() << '\n';
   for(auto &e : R){
      cout << e << ' ';
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
