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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 3e5 + 10; 

int a[3][N];
int n1, n2, n3;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n1 >> n2 >> n3;
   int sm = 0;
   int sa = 0;
   for (int i = 0; i < n1; ++i) {
      cin >> a[0][i];
      sa += a[0][i];
      sm += a[0][i];
   }
   int sb = 0;
   for (int i = 0; i < n2; ++i) {
      cin >> a[1][i];
      sb += a[1][i];
      sm += a[1][i];
   }
   int sc = 0;
   for (int i = 0; i < n3; ++i) {
      cin >> a[2][i];
      sc += a[2][i];
      sm += a[2][i];
   }

   sort(a[0] ,a[0] + n1);
   sort(a[1] ,a[1] + n2);
   sort(a[2] ,a[2] + n3);

   int ans = 0;

   ans = sm - 2 * min({a[0][0] + a[1][0] , a[1][0] + a[2][0], a[0][0] + a[2][0]});
   ans = max({ans, sm - 2 * sa, sm - 2 * sb, sm - 2 * sc});

   cout << ans << '\n';
   return 0;
} 