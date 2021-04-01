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
   int n, m;
   cin >> n >> m;
   vector <int> a(n), b(m);
   vector <int> cnt(101);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
   }
   for (int i = 0; i < m; ++i) {
      cin >> b[i];
      cnt[b[i]]++;
   }
   int ans = 0;
   for (int i = 0; i < 101; ++i) {
      ans += (cnt[i] == 2);
   } 
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
 