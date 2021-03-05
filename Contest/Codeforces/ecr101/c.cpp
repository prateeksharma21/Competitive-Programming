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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<int> mx(n);
   vector<int> mn(n);
   for (int i = 0; i < n; ++i) {
      mn[i] = a[i] + k;
      mx[i] = a[i] + 2 * k - 1;
   }
   mx[0] = a[0] + k;
   mx[n - 1] = a[n - 1] + k;
   for (int i = 1; i < n; ++i) {
      int l = mn[i - 1] - k + 1;
      int r = mx[i - 1] + k - 1;
      if (max(l, mn[i]) < min(r, mx[i])) {
         mn[i] = max(l, mn[i]);
         mx[i] = min(r, mx[i]);
      } else {
         cout << "No\n";
         return;
      }
   } 
   cout << "Yes\n";
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