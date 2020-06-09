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
   vector<int> A(n);
   f(i,0,n){
      cin >> A[i];
   }
   int ans = 0;
   if(n == 1){
      cout << A[0] << '\n';
      return;
   }
   if(n == 2){
      cout << (A[0]|A[1]) << '\n';
      return;
   }
   f(i,0,n){
      f(j,i+1,n){
         f(k,j+1,n){
            int R = (A[i]|A[j]);
            R = (R|A[k]);
            ans = max(ans,R);
         }
      }
   }
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   // cin >> tt;
   f(i,0,tt) test();   
   return 0;
}