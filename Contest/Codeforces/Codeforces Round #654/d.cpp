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

   int v = k/n;
   vector<int> A(n);
   f(i,0,n){
      A[i] = v;
   }
   int rem = k%n;
   int i = n-1;
   int val = 0;
   if(rem){
      val = 2;
   }
   while(rem){
      A[i]++;
      i--;
      rem--;
   }
   // debug(A);
   vector<vector<int>> R(n,vector<int>(n));
   f(i,0,n){
      int c = i;
      while(A[i]){
         R[i][c] = 1;
         c ++;
         c %= n;
         --A[i];
      }
   }
   cout << val << '\n';
   f(i,0,n){
      f(j,0,n){
         cout << R[i][j];
      }
      cout << '\n';
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
