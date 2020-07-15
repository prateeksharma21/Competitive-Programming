#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector<array<int,3>> R;
   for(int i = 1; i*i <= n; ++i){
      if(n % i == 0){
         R.pb({max(n-i,i),i,n-i});
         R.pb({max(n-n/i,n/i),n/i,n-n/i});
      }
   }
   sort(all(R));
   cout << R[0][1] << ' ' << R[0][2] << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
