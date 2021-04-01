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
   vector<int> A;
   vector<int> done(n + 1);
   int x = n;
   while (x != 2) {
      A.push_back(x);
      done[x] = 1;
      int sq = sqrt(x);
      if (sq * sq == x) {
         x = sq;
      } else {
         x = sq + 1;
      }
   }
   done[2] = 1;
   A.push_back(2);
   reverse(all(A));
   vector<pair<int, int>> res;
   for (int i = 2; i <= n; ++i) {
      if (done[i]) continue;
      res.push_back({n, i});
   }
   int sz = A.size();
   for (int i = sz - 2; i >= 0; --i) {
      res.push_back({A[i], A[i + 1]});
      res.push_back({A[i], A[i + 1]});
   }
   cout << res.size() << '\n';
   for (auto [x, y] : res) {
      cout << y << ' ' << x << '\n';
   }
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