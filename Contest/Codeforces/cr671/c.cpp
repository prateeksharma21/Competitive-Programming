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
   int n,x;
   cin >> n >> x;
   vector<int> A(n);
   int v = 0;
   vector<int> req(n);
   int all_eq = 1;
   int sm = 0;
   int chk = 0;
   for(int i = 0; i < n; ++i){
      cin >> A[i];   
      req[i] = x-A[i];
      sm += req[i];
      chk |= (A[i] == x);
      all_eq &= (req[i] == 0);
   }
   if(all_eq){
      cout << "0\n";
      return;
   }
   if(sm == 0 or chk){
      cout << "1\n";
      return;
   }
   cout << "2\n";
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
