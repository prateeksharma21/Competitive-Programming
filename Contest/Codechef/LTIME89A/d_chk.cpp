#ifdef Prateek
  #include "\Prateek.h"
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
   int n = 8;
   vector<int> A(n);
   iota(all(A),12);
   int tot = accumulate(all(A),0ll);
   map<int, bool> poss;
   debug(tot);
   for(int i = 0; i < (1 << n) ; ++i) {
      int sm = 0;
      for(int j = 0; j < n; ++j) {
         if((i >> j) & 1) {
            sm += A[j];
         }
      }
      if(sm)
      poss[sm] = true;
   }
   vector<int> not_possible;
   for(int i = 1; i <= tot; ++i) {
      if(poss.find(i) != poss.end()) {

      } else {
         not_possible.push_back(i);
      }
   }
   debug(not_possible);
   debug(poss.size());
   return 0;
}