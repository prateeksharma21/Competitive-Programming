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
   vector<int> b(n);
   vector<int> cnt(2 * n + 1);
   for (int &i : b) {
      cin >> i;
      cnt[i] = 1;
   }
   int mx = 0, mn = 0;
   int c = 0;
   int t = 2 * n;
   for (int i = n - 1; i >= 0; --i) {
      int d = t - b[i];
      if (d >= 1) {
         ++c;
         --t;
      }
      --t;
   }
   mx = c;
   c = 0;
   t = 1;
   for (int i = 0; i < n; ++i) {
      int d = b[i] - t;
      if (d >= 1) {
         ++c;
         ++t;
      }
      ++t;
   }
   mn = n - c;
   cout << mx - mn + 1 << '\n';
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