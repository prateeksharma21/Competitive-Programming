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
   int n,m;
   cin >> n >> m;
   vector<int> R(n+1),C(m+1);
   vector<vector<int>> A(n+2,vector<int>(m+2));
   f(i,1,n+1){
      f(j,1,m+1){
         cin >> A[i][j];
         if(A[i][j]){
            R[i] = C[j] = 1;
         }
      }
   }
   int c = 0;
   f(i,1,n+1){
      f(j,1,m+1){
         if(!R[i] and !C[j]){
            c++;
            R[i] = C[j] = 1;
         }
      }
   }
   debug(c);
   if(c & 1){
      cout << "Ashish\n";
   }else{
      cout << "Vivek\n";
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
