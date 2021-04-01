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
   vector<array<int, 2>> A(n);
   int cur = 0;
   for (int i = 0, x; i < n; ++i) {
      cin >> x;
      cur += x;
      A[i] = {x, i};
   }
   int other = 0;
   sort(all(A));
   debug(A);
   vector<int> res;
   int nxt = 0;
   for (int i = n - 1; i >= 0; --i) {
      if (i + 1 < n and A[i][0] == A[i + 1][0]) {
         res.push_back(A[i][1]);
         cur -= A[i][0];
         continue;
      }
      if (cur >= nxt) {
         res.push_back(A[i][1]);
      } else {
         break;
      }
      cur -= A[i][0];
      nxt = A[i][0];
   }
   sort(all(res));
   cout << res.size() << '\n';
   for (int i : res) {
      cout << i + 1<< ' ';
   }
   cout << '\n';
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