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
   vector<int> R(n+1);
   int i = 2, j = 1;
   int sm = 0;
   while(sm+2 < 2*n){
      cout << "? " << j << ' ' << i << endl;
      int q1,q2;
      cin >> q1;
      cout << "? " << i << ' ' << j << endl;
      cin >> q2;
      if(q1 > q2){
         R[j] = q1;
         j = i;
      }else{
         R[i] = q2;
      }
      ++i;
      sm += 2;
   }
   cout << "! ";
   for(int i = 1; i <= n; ++i){
      if(R[i] == 0){
         cout << n << ' ';
      }else{
         cout << R[i] << ' ';
      }
   }
   cout << endl;
   return 0;
}