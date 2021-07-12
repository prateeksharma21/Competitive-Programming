#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#include <bits/stdc++.h>
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n = getRand(1, 500);
   vector<int> a(n);
   cout << n << '\n';
   int v = getRand(1, MOD);
   srand(time(0));
   iota(all(a), 1LL);
   random_shuffle(all(a));
   for (int i : a) {
      cout << i << ' ';
   }
   cout << '\n';
   return 0;
}