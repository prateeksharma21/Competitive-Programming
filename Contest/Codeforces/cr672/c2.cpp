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
   int n, q;
   cin >> n >> q;
   vector<int> A(n+2,-1);
   for(int i = 1; i <= n; ++i) {
      cin >> A[i];
   }

   int ans = 0;

   auto Add = [&](int i) {
      if(i == 0 or i == n+1) return;
      if(A[i] > A[i-1] and A[i] > A[i+1]) ans += A[i];
      if(A[i] < A[i-1] and A[i] < A[i+1]) ans -= A[i];
   };

   auto Remove = [&](int i) {
      if(i == 0 or i == n+1) return;
      if(A[i] > A[i-1] and A[i] > A[i+1]) ans -= A[i];
      if(A[i] < A[i-1] and A[i] < A[i+1]) ans += A[i];
   };

   for(int i = 1; i <= n; ++i) {
      Add(i);
   }

   cout << ans << '\n';
   
   while(q--) {
      int l, r;
      cin >> l >> r;
      set<int> s;
      s.insert(l);
      s.insert(l-1);
      s.insert(l+1);
      s.insert(r);
      s.insert(r-1);
      s.insert(r+1);
      for(int i : s){
         Remove(i);
      }
      swap(A[l],A[r]);
      for(int i : s){
         Add(i);
      }
      cout << ans << '\n';
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
 