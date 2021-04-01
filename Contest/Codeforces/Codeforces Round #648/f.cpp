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
using ld = long double;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector<int> A(n),B(n);
   f(i,0,n){
      cin >> A[i];
   }
   f(i,0,n){
      cin >> B[i];
   }
   if(n & 1){
      if(A[n/2] != B[n/2]){
         cout << "NO\n";
         return;
      }
   }
   vector<pair<int, int>> X,Y;
   f(i,0,n/2){
      X.pb({min(A[i],A[n-1-i]),max(A[i],A[n-1-i])});
      Y.pb({min(B[i],B[n-1-i]),max(B[i],B[n-1-i])});
   }
   sort(all(X));
   sort(all(Y));
   if(X == Y){
      cout << "YES\n";
   }else{
      cout << "NO\n";
   }
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