#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   auto A = vector(n, vector(n, '0'));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> A[i][j];
      }
   }
   auto B = A;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> B[i][j];
      }
   }

   auto row = vector(n, 0);
   auto col = row;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         row[i] = (A[i][j] != B[i][j]);
      }
   }

   for (int i = 0; i < n; ++i) {
      if (row[i]) {
         for (int j = 0; j < n; ++j) {
            A[i][j] = (A[i][j] == '1' ? '0' : '1');
         }
      }
   }

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         col[j] = (A[i][j] != B[i][j]);
      }
   }

   for (int i = 0; i < n; ++i) {
      if (col[i]) {
         for (int j = 0; j < n; ++j) {
            A[j][i] = (A[j][i] == '1' ? '0' : '1');
         }   
      }
   }

   cout << (A == B ? "YES\n" : "NO\n");
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}