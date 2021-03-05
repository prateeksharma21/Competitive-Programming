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
   int n, m;
   cin >> n >> m;
   vector<int> a(n), b(m);
   for (int &i : a) cin >> i;
   for (int &i : b) cin >> i;
   sort(all(a));
   int gc = 0;
   for (int i = 1; i < n; ++i) {
      a[i] -= a[0];
      gc = gcd(a[i], gc);
   }
   for (int i = 0; i < m; ++i) {
      int x = b[i];
      cout << gcd(a[0] + x, gc) << ' ';
   }
   cout << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   // cin >> tt;
   f(i,0,tt) test();   
   return 0;
}