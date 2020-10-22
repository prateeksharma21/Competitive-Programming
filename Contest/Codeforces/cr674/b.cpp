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
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n, m;
   cin >> n >> m;
   int A[n][2][2];
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < 2; ++j) {
         for(int k = 0; k < 2; ++k) {
            cin >> A[i][j][k];
         }
      }
   }
   if(m & 1) {
      cout << "NO\n";
      return;
   }
   for(int i = 0; i < n; ++i) {
      if(A[i][0][1] == A[i][1][0]) {
         cout << "YES\n";
         return;
      }
   }
   cout << "NO\n";
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
