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

bool A[500][500][510];

void test(){
   int n, m;
   cin >> n >> m;
   vector<string> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         for (int k = 0; k <= m + 2; ++k) {
            A[i][j][k] = false;
         }
      }
   }
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (s[i][j] == '*') {
            A[i][j][1] = true;
            int l = j - 1, h = j + 1;
            ++ans;
            if (i == 0) continue;
            for (int len = 3; l >= 0 and h < m; len += 2, l--, h++) {
               if (s[i][l] == '*' and s[i][h] == '*' and A[i - 1][j][len - 2]) {
                  ++ans;
                  A[i][j][len] = true;
               } else {
                  break;
               }
            }            
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
   f(i,0,tt) test();   
   return 0;
}