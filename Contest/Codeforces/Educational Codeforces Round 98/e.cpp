#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")             //Enable AVX
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
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 
const int SQ = 40;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m, k;
   cin >> n >> m >> k;
   vector<array<int,2>> A(m);
   for (auto &[x, y] : A) {
      cin >> x >> y;
   }

   vector<vector<int>> val(n+1, vector<int>(m));

   for (int i = 1; i <= n - k + 1; ++i) {
      int l = i, r = i + k - 1;
      for (int j = 0; j < m; ++j) {
         val[i][j] = max(0, 1 + min(r, A[j][1]) - max(l, A[j][0]));
      }
   }

   int ans = 0;
   int r;
   for (int i = 1; i <= n - k + 1; ++i) {
      r = 0;
      for (int k = 0; k < m; ++k) {
         r += val[i][k];
      }
      ans = max(ans, r);
      for (int j = i + 1; j <= n - k + 1; ++j) {
         r = 0;
         for (int k = 0; k < m; ++k) {
            r += max(val[i][k], val[j][k]);
         }
         ans = max(ans, r);
      }
   }

   cout << ans << '\n';
   return 0;
}