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
   vector<vector<int>> a(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   vector<vector<int>> left(n, vector<int>(m));
   vector<vector<int>> right(n, vector<int>(m));
   vector<vector<int>> up(n, vector<int>(m));
   vector<vector<int>> down(n, vector<int>(m));
   
   for (int i = 0; i < n; ++i) {
      for (int j = 0, k = 0; j < m; j = k) {
         while (k < m and a[i][j] == a[i][k]) ++k;
         if (a[i][j] == 0) continue;
         for (int l = j; l < k; ++l) {
            left[i][l] = k - l;
            right[i][l] = l - j + 1;
         }
      }
   }

   for (int i = 0; i < m; ++i) {
      for (int j = 0, k = 0; j < n; j = k) {
         while (k < n and a[j][i] == a[k][i]) ++k;
         if (a[j][i] == 0) continue;
         for (int l = j; l < k; ++l) {
            down[l][i] = k - l;
            up[l][i] = l - j + 1;
         }
      }
   }

   int ans = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         ans += max(0LL, min(up[i][j] / 2, right[i][j]) - 1);
         ans += max(0LL, min(right[i][j] / 2, up[i][j]) - 1);

         ans += max(0LL, min(up[i][j] / 2, left[i][j]) - 1);
         ans += max(0LL, min(left[i][j] / 2, up[i][j]) - 1);

         ans += max(0LL, min(down[i][j] / 2, right[i][j]) - 1);
         ans += max(0LL, min(right[i][j] / 2, down[i][j]) - 1);

         ans += max(0LL, min(down[i][j] / 2, left[i][j]) - 1);
         ans += max(0LL, min(left[i][j] / 2, down[i][j]) - 1);
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