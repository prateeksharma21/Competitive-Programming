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
   vector<int> pos,neg;
   int c0 = 0;
   for(int i = 0; i < n; ++i){
      cin >> A[i];
      if(A[i] > 0){
         pos.push_back(A[i]);
      }else if(A[i] < 0){
         neg.push_back(A[i]);
      }else{
         ++c0;
      }
   }
   sort(all(pos),greater<int>());
   sort(all(neg));
   int mx = -1e18;
   for(int p = 0; p <= 5; ++p){
      for(int n = 0; n <= 5; ++n){
         for(int z = 0; z <= 5; ++z){
            if(p+n+z != 5) continue;
            if(p > pos.size() or n > neg.size() or z > c0) continue;
            if(z){
               mx = max(mx,0ll);
            }else{
               int pm = 1;
               for(int i = 0; i < p; ++i){
                  pm *= pos[i];
               }
               int nm = 1;
               for(int i = 0; i < n; ++i){
                  nm *= neg[i];
               }
               int pn = 1;
               int j = (int)neg.size()-1;
               for(int i = 0; i < n; ++i){
                  pn *= neg[j];
                  --j;
               }
               mx = max({mx,pm*nm,pm*pn});
            }
         }
      }
   }
   cout << mx << '\n';
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
