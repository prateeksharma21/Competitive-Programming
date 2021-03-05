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
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector <int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   reverse(all(a));
   int ans = 0;
   int res = 0;
   vector<int> op(n);
   for (int i = 1; i < n; ++i) {
      op[i] = abs(a[i] - a[i-1]);
      res += op[i];
   }
   debug(op);
   ans = res;
   for (int i = 1; i < n-1; ++i) {
      ans = min(ans, res - op[i] - op[i+1] + abs(a[i+1] - a[i-1]));
   }   
   ans = min(ans, res - op.back());
   ans = min(ans, res - op[1]);
   cout << ans << '\n';
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
