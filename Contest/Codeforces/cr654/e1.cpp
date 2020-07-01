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
const int MOD = 1e9+7, N = 1e5 + 1; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,p;
   cin >> n >> p;
   vector<int> A(n);
   f(i,0,n){
      cin >> A[i];
   }
   sort(all(A));
   int mx = A.back();
   vector<int> ans;
   f(i,1,mx+1){
      int v = i;
      int j = 0;
      int val = 1;
      f(k,0,n){      
         while(j < n and A[j] <= v){
            j++;
         }
         v++;
         val *= (j-k);
         val %= p;
      }
      if(val){
         ans.pb(i);
      }
   }
   cout << ans.size() << '\n';
   for(auto &e : ans){
      cout << e << ' ';
   }
   cout << '\n';
   // debug(ans);
   return 0;
} 