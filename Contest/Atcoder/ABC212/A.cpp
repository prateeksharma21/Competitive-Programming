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
   int a, b;
   cin >> a >> b;
   if (a and !b) {
      cout << "Gold";
   } else if (!a and b) {
      cout << "Silver";
   } else {
      cout << "Alloy";
   }
   return 0;
}