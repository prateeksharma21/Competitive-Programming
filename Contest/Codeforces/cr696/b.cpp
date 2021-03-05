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

vector<int> Prime;

void sieve(int n){
   vector<bool> prime(n+1,true);
   prime[0] = prime[1] = false;
   for(int i=2;i<=n;i++){
      if(prime[i]){
         Prime.push_back(i);
         for(int j=i*i; j<=n; j+=i){
            prime[j] = false;
         }
      }
   }
}


void test(){
   int d;
   cin >> d;
   int f = 0;
   for (int i : Prime) {
      if (i - 1 >= d) {
         f = i;
         break;
      }
   }
   int s = 0;
   for (int i : Prime) {
      if (i - f >= d) {
         s = i;
         break;
      }
   }
   cout << f * s  << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   sieve(N);
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}