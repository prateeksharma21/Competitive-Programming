#ifdef Prateek
  #include "\Prateek.h"
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
   int nn = n;
   vector < pair<int, int>> F;
   for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
         F.push_back({i, 0});
         while (n % i == 0) {
            F.back().second++;
            n /= i;
         }
      }
   }
   if (n > 1) {
      F.push_back({n,1});
   }
   int mx = 0, val;
   for (auto i : F) {
      if (mx < i.second) {
         mx = i.second;
         val = i.first;
      }
   }
   cout << mx << '\n';
   int done = 1;
   for (int i = 0; i < mx-1; ++i) {
      done *= val;
      cout << val << ' ';
   }
   cout << nn / done << '\n';
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