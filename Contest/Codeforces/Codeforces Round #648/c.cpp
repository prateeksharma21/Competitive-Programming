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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> A(n),B(n);
   vector<int> C(n+2);
   f(i,0,n){
      cin >> A[i];
   }
   vector<int> P(n+1);
   f(i,0,n){
      cin >> B[i];
      P[B[i]] = i;
   }
   f(i,0,n){
      int pos = P[A[i]];
      if(pos>=i){
         C[pos-i]++;
      }else{
         C[n-abs(pos-i)]++;
      }
   }
   int ans = 0;
   f(i,0,n+2){
      ans = max(ans,C[i]);
   }
   cout << ans << '\n';
   return 0;
}