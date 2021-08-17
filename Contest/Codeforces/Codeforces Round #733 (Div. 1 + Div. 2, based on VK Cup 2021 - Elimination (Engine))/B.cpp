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
   int n, m;
   cin >> n >> m;

   vector<vector<int>> res(n + 2, vector<int>(m + 2));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         int k = (res[i - 1][j] | res[i][j - 1] | res[i - 1][j - 1] | res[i - 1][j + 1]);
         if (i > 1 and i < n and j > 1 and j < m) k = 1;
         cout << (k ^ 1);
         res[i][j] = k ^ 1;
      }
      cout << '\n';
   } 

   // if (n & 1 and m & 1) {
   //    for (int i = 0; i < n; ++i) {
   //       for (int j = 0; j < m; ++j) {
   //          if (i == 0 or i == n - 1) {
   //             cout << (((j & 1) + 1) & 1);
   //          } else if (i % 2 == 0 and (j == 0 or j == m - 1)) {
   //             cout << 1;
   //          } else {
   //             cout << 0;
   //          }
   //       }
   //       cout << '\n';
   //    }
   //    return;
   // }
   // if (n % 2 == 0 and m % 2 == 0) {
   //    for (int i = 0; i < m - 2; ++i) {
   //       cout << (i & 1);
   //    }
   //    cout << "00" << '\n';
   //    for (int i = 1; i < n - 1; ++i) {
   //       for (int j = 0; j < m; ++j) {
   //          if (i & 1 and j == m - 1) {
   //             cout << 1;
   //          } else if (i % 2 == 0 and j == 0) {
   //             cout << 1;
   //          } else {
   //             cout << 0;
   //          }
   //       }
   //       cout << '\n';
   //    }
   //    cout << "00";
   //    for (int i = 1; i <= m - 2; ++i) {
   //       cout << (i & 1);
   //    }
   //    cout << '\n';
   //    return;
   // }
   // if (n & 1) {
   //    for (int i = 0; i < m; ++i) {
   //       cout << (i & 1);
   //    }
   //    cout << '\n';
   //    for (int i = 0; i < n - 2; ++i) {
   //       for (int j = 0; j < m; ++j) {
   //          if (i & 1 and (j == m - 1 or j == 0)) {
   //             cout << 1;
   //          } else {
   //             cout << 0;
   //          }
   //       }
   //       cout << '\n';
   //    }
   //    for (int i = 1; i <= m; ++i) {
   //       cout << (i & 1);
   //    }
   //    cout << '\n';
   //    return;
   // }
   // for (int i = 0; i < )
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