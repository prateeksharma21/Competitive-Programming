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
const int MOD = 1e9+7, N = 500 + 10; 

int spf[N];
vector<int> prime;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   for (int i = 2; i < N; ++i) {
      if (spf[i] == 0) {
         spf[i] = i;
         prime.push_back(i);
         for (int j = i * i; j < N; j += i) {
            if (!spf[j]) spf[j] = i;
         }
      }
   }
   srand(time(0));
   int t = 1;
   cout << t << '\n';
   int rem = getRand(2, 10);
   random_shuffle(all(prime));
   int p = 0;
   vector<array<int, 2>> res;
   int n = getRand(1, 50);
   for (int i = 0; i < n and rem; ++i) {
      int v = getRand(0, rem);
      if (i == 9) v = rem;
      if (!v) continue;
      res.push_back({prime[p], v});
      ++p;
      rem -= v;
   } 
   cout << res.size() << '\n';
   for (auto [x, y] : res) {
      cout << x << ' ' << y << '\n';
   }
   return 0;
}