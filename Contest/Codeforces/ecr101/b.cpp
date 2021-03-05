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
   vector<int> r(n);
   int cur = 0;
   int mx1 = 0;
   for (int &i : r) {
      cin >> i;
      cur += i;
      mx1 = max(mx1, cur);
   }
   int m;
   cin >> m;
   vector<int> b(m);
   cur = 0;
   int mx2 = 0;
   for (int &i : b) {
      cin >> i;
      cur += i;
      mx2 = max(mx2, cur);
   }
   cout << mx1 + mx2 << '\n';
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