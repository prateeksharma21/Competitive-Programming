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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void test(){
   int n, m;
   cin >> n >> m;
   vector<vector<int>> a(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }   
   int ans = 0;
   set<array<int, 3>, greater<array<int,3>>> s;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         s.insert({a[i][j], i, j});
      }
   }

   auto valid = [&](int x, int y) {
      return x >= 0 and x < n and y >= 0 and y < m;
   };

   while (!s.empty()) {
      auto [v, x, y] = *s.begin();
      s.erase(s.begin());
      for (int i = 0; i < 4; ++i) {
         int nx = x + dx[i], ny = y + dy[i];
         if (valid(nx, ny) and abs(a[x][y] - a[nx][ny]) > 1) {
            int d = abs(a[x][y] - a[nx][ny]);
            s.erase({a[nx][ny], nx, ny});
            ans += d - 1;
            a[nx][ny] = a[x][y] - 1;
            s.insert({a[nx][ny], nx, ny});
         }
      }
   }

   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt){
      cout << "Case #" << i+1 << ": ";
      test();   
   }
   return 0;
}