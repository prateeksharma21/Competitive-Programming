#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 2e5 + 10; 
const int INF = 1e17;

int n;
int dp[N][11];
vector<int> val[N][4];

int dfs(int pos, int cur) {
   if (pos == -1) {
      if (cur == 0) return 0;
      return -INF;
   }
   int &ans = dp[pos][cur];
   if (ans != -1) return ans;
   ans = 0;
   for (int take = 0; take <= 3; ++take) {
      for (int a = 0; a < 4; ++a) {
         for (int b = 0; b < 4; ++b) {
            int c = take - a - b;
            if (c < 0) continue;
            if (a > val[pos][1].size() or b > val[pos][2].size() or c > val[pos][3].size()) continue;
            if (a + b * 2 + c * 3 > 3) continue; 
            vector<int> idx, choosen;
            int total = a + b + c;
            for (int i = 0; i < total; ++i) idx.push_back((cur - i + 10) % 10);
            for (int i = 0; i < a; ++i) choosen.push_back(val[pos][1][i]); 
            for (int i = 0; i < b; ++i) choosen.push_back(val[pos][2][i]); 
            for (int i = 0; i < c; ++i) choosen.push_back(val[pos][3][i]);
            sort(all(choosen), greater{});
            if (count(all(idx), 0)) {
               ans = max(ans, dfs(pos - 1, (cur - total + 10) % 10) + accumulate(all(choosen), 0LL) + choosen[0]);
            } else {
               ans = max(ans, dfs(pos - 1, (cur - total + 10) % 10) + accumulate(all(choosen), 0LL));
            }
         }
      }
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   cin >> n;
   for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      while (k--) {
         int c, d;
         cin >> c >> d;
         val[i][c].push_back(d);
      }
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= 3; ++j) {
         sort(all(val[i][j]), greater{});
      }
   }
   int ans = 0;
   for (int i = 0; i < 10; ++i) {
      ans = max(ans, dfs(n - 1, i));
   }
   cout << ans << '\n';
   return 0;
}