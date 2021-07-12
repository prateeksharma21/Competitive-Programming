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
const int MOD = 1e9+7, N = 1e5; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout << 1 << '\n';
   int n = 100000;
   cout << n << '\n';
   vector<int> a;
   for (int i = 0; i < 20; ++i) {
      a.push_back(1 << (i + 1));
   }
   // debug(a);
   srand(time(0));
   random_shuffle(all(a));
   for (int i = 0; i < n; ++i) {
      cout << a[getRand(0,  19)] << ' ';
   }  
   return 0;
}