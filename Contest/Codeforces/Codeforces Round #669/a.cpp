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
   vector<int> C(2);
   for(int i = 0; i < n; ++i){
      cin >> A[i];
      C[A[i]]++;
   }
   if(C[0] >= C[1]){
      cout << C[0] << '\n';
      for(int i = 0; i < C[0]; ++i){
         cout << "0 ";
      }
   }else{
      if(C[1] & 1) C[1]--;
      cout << C[1] << '\n';
      for(int i = 0; i < C[1]; ++i){
         cout << "1 ";
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
