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
const int MOD = 1e9+7, N = 200 + 10; 

int dp[N][N];
int a[N];

int dfs(int i, int wt) {
   if (wt < 0) return 0;
   if (i == -1) {
      return wt == 0;
   }
   int &ans = dp[i][wt];
   if (ans != -1) return ans;
   ans = (dfs(i - 1, wt) | dfs(i - 1, (wt - a[i] + 200) % 200));
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp, -1, sizeof dp);
   int n;
   cin >> n;
   vector<int> cnt(200);
   int sm = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] %= 200;
      sm += a[i];
      cnt[a[i]]++;
   }
   for (int i = 0; i < 200; ++i) {
      if (cnt[i] > 1) {
         vector<int> v;
         for (int j = 0; j < n; ++j) {
            if (a[j] == i) {
               v.push_back(j + 1);
            }
         }
         cout << "YES\n";
         cout << 1 << ' ' << v.back() << '\n';
         cout << 1 << ' ' << v.front() << '\n';
         return 0;
      }
   }

   auto get = [&](int total) {
      vector<int> v;
      for (int j = n - 1; j >= 0; --j) {
         if (dfs(j - 1, (total - a[j] + 200) % 200)) {
            v.push_back(j + 1);
            total = (total - a[j] + 200) % 200;
         }
      }
      reverse(all(v));
      return v;
   };


   for (int i = 0; i < 200; ++i) {
      if (dfs(n - 1, i)) {
         vector<int> b = get(i);
         if (b.empty()) continue;
         vector<array<int, 2>> oth;
         vector<int> mark(n);
         for (int i : b) {
            mark[i - 1] = 1;
         }
         for (int j = 0; j < n; ++j) {
            if (!mark[j]) {
               oth.push_back({a[j], j});
            }
         }
         int sz = oth.size();

         // debug(oth);
         vector<vector<int>> cur(sz, vector<int>(201, -1));
         function<int(int, int)> dfs = [&](int i, int wt) {
            if (wt < 0) return 0LL;
            if (i == -1) {
               return int(wt == 0);
            }
            int &ans = cur[i][wt];
            if (ans != -1) return ans;
            ans = dfs(i - 1, wt) | dfs(i - 1, (wt - oth[i][0] + 200) % 200);
            return ans;
         };

         if (dfs(sz - 1, i)) {
            cout << "YES\n";
            cout << b.size() << ' ';
            for (int i : b) cout << i << ' ';
            cout << '\n';
            vector<int> v;
            int total = i;
            for (int j = sz - 1; j >= 0; --j) {
               if (dfs(j - 1, (total - oth[j][0] + 200) % 200)) {
                  v.push_back(oth[j][1] + 1);
                  total = (total - oth[j][0] + 200) % 200;
               }
            }
            reverse(all(v));
            b = v;
            cout << b.size() << ' ';
            for (int i : b) cout << i << ' ';
            cout << '\n';
            return 0;
         }
      }
   }
   cout << "NO\n";
   return 0;
}