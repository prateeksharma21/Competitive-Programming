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
   vector<int> A(n);
   for(int i = 0; i < n; ++i){
      cin >> A[i];
   }
   if(n == 1){
      cout << "1 1\n0\n1 1\n0\n1 1\n" << -A[0] << '\n';
      return 0;
   }
   cout << 2 << ' '<< n << '\n';
   for(int i = 1; i < n; ++i){
      int v = A[i]*(n-1);
      cout << v << ' ';
      A[i] += v;
      assert(A[i]%n == 0);
   }
   cout << '\n';
   cout << 1 << ' ' << n << '\n';
   cout << "0 ";
   for(int i = 1; i < n; ++i){
      cout << -A[i] << ' ';
   }
   cout << '\n';
   cout << 1 << ' ' << 1 << '\n';
   cout << -A[0] << '\n';
   return 0;
}