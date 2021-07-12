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
const int MOD = 1e9, N = 1e5 + 10; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout << 1 << '\n';
   cout << getRand(1, MOD) << ' ' << getRand(1, MOD) << ' ' << getRand(1, 100) << ' ' << getRand(1, 100) << '\n';  
   return 0;
}