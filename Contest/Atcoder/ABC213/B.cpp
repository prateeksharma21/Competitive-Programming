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
   int n;
   cin >> n;
   vector<int> a(n);
   vector<int> b(n);
   iota(all(b), 0LL);
   for (int &i : a) {
      cin >> i;
   }
   sort(all(b), [&](int x, int y){
      return a[x] > a[y];
   });
   cout << b[1] + 1;
   return 0;
}