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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   srand(time(0));
   int n = rand() % 10 + 2;
   cout << n << '\n';
   for (int i = 0; i < n; ++i) {
      cout << rand() % 1000 + 1 << ' ';
   }
   cout << '\n';
   return 0;
}