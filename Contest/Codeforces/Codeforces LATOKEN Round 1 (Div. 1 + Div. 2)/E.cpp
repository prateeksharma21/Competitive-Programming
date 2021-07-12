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
const int MOD = 1e9+7, N = 500 + 10; 

int n, k;
int dp[N][N];
vector<int> a = {0, 2, 1, 7, 5, 6};
array<int, 2> nxt[N][N];

int dfs(int x, int y) {
   if (x > n or x < 0 or y > n or y < 0) return MOD;
   assert(x + y == n);
   if (y == n) {
      return 0;
   }
   int &ans = dp[x][y];
   if (ans != -1) return ans;
   ans = MOD;
   for (int i = 0; i <= k; ++i) {
      if (x - i >= 0 and y - (k - i) >= 0) {
         int nx = x - i + (k - i);
         int ny = y + i - (k - i);
         int val = 1 + dfs(nx, ny);
         if (val < ans) {
            ans = val;
            nxt[x][y] = {nx, ny};
         }
      }
   }
   return ans;
}

int query(vector<int> a) {
   cout << "? ";
   for (int i : a) {
      cout << i << ' ';
   }
   cout << endl;
   int x;
   cin >> x;
   return x;
}

// int query(vector<int> q) {
//    int res = 0;
//    for (int i : q) {
//       res ^= a[i];
//    }
//    return res;
// } 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   memset(dp, -1, sizeof dp);

   int res = dfs(n, 0);

   if (res == MOD) {
      cout << -1 << endl;
      return 0;
   }

   int x = n, y = 0;
   vector<array<int, 2>> ans;
   while (!(x == 0 and y == n)) {
      ans.push_back({x, y});
      auto [nx, ny] = nxt[x][y];
      x = nx, y = ny;
   }
   ans.push_back({x, y});
   ans.erase(ans.begin());
   vector<int> cur(n + 1);
   x = n, y = 0;
   int result = 0;
   // debug(res);
   // debug(ans);
   for (int t = 0; t < res; ++t) {
      for (int i = 0; i <= k; ++i) {
         if (x - i >= 0 and y - (k - i) >= 0) {
            int nx = x - i + (k - i);
            int ny = y + i - (k - i);
            if (nx == ans[t][0] and ny == ans[t][1]) {
               vector<int> q;
               int req0 = i;
               for (int x = 1; x <= n and req0; ++x) {
                  if (cur[x] == 0) {
                     q.push_back(x);
                     --req0;
                  }
               }
               int req1 = k - i;
               for (int x = 1; x <= n and req1; ++x) {
                  if (cur[x] == 1) {
                     q.push_back(x);
                     --req1;
                  }
               }
               result ^= query(q);
               x = nx, y = ny;
               for (int i : q) {
                  cur[i] ^= 1;
               }
               break;
            }
         }
      }
   }
   cout << "! " << result << '\n';

   return 0;
}