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
   vector<int> a(n);
   for (int &i : a) {
      cin >> i;
   }
   int cur = 0;
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      cur += a[i];
      int cnt = 1;
      int sm = 0;
      for (int j = i + 1; j < n; ++j) {
         sm += a[j];
         if (sm == cur) {
            sm = 0;
            ++cnt;
         }
         if (sm > cur) break;
      }
      if (sm == 0) {
         ans = max(ans, cnt);
      }
   }
   cout << n - ans << '\n';
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