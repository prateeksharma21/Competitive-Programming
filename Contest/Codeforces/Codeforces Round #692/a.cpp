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
   vector<array<int, 2>> A(m);
   vector<int> to(n + 1);
   vector<int> vis(n + 1);

   for (auto &[x, y] : A) {
      cin >> x >> y;
      to[y] = x;
   }

   debug(A);

   int ans = m;

   for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      if (to[i] == i) {
         vis[i] = 1;
         --ans;
         continue;
      }
      int cur = i;
      while (!vis[cur]) {
         debug(cur, i);
         vis[cur] = true;
         cur = to[cur];
         if (cur == -1) break;
      }
      if (cur == i) ++ans;
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