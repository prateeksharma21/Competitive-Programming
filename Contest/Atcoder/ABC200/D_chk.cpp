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

int dp[N][N * N];
int a[N];

int dfs(int i, int wt) {
   if (wt < 0) return 0;
   if (i == -1) {
      return wt == 0;
   }
   int &ans = dp[i][wt];
   if (ans != -1) return ans;
   ans = (dfs(i - 1, wt) | dfs(i - 1, wt - a[i]));
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

   for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
         cout << "YES\n";
         vector<int> b = {i, (i + 1) % n};
         sort(all(b));
         cout << 2 << ' ' << 1 + b.front() << ' ' << 1 + b.back() << '\n';
         cout << 1 << ' ' << (i + 1) % n + 1 << '\n';
         return 0;
      }
   }

   auto get = [&](int total) {
      vector<int> v;
      for (int j = n - 1; j >= 0; --j) {
         if (dfs(j - 1, total - a[j])) {
            v.push_back(j + 1);
            total -= a[j];
         }
      }
      reverse(all(v));
      return v;
   };


   vector<int> prv(200, -1);
   for (int i = 1; i < sm; i++) {
      if (dfs(n - 1, i)) {
         if (prv[i % 200] == -1) {
            prv[i % 200] = i;
            continue;
         }
         cout << "YES\n";
         vector<int> a = get(prv[i % 200]);
         vector<int> b = get(i);
         cout << a.size() << ' ';
         for (int i : a) {
            cout << i << ' ';
         }
         cout << '\n';
         cout << b.size() << ' ';
         for (int i : b) {
            cout << i << ' ';
         }
         cout << '\n';
         return 0;
      }
   } 

   auto solve = [&](int wt) {
      vector<int> ff = get(wt);
      if (ff.empty()) return;
      vector<int> mark(n);
      for (int i : ff) {
         mark[i - 1] = 1;
      }
      vector<int> A;
      for (int i = 0; i < n; ++i) {
         if (!mark[i]) {
            A.push_back(a[i]);
         }
      }
      int sz = A.size();
      vector<vector<int>> cur(sz, vector<int>(wt + 1, -1));
      function<int(int, int)> solve = [&](int i, int w) {
         if (w < 0) return int(0);
         if (i == -1) return int(w == 0);
         int &ans = cur[i][w];
         if (ans != -1) return ans;
         ans = solve(i - 1, w) | solve(i - 1, w - A[i]);
         return ans;
      };

      if (solve(sz - 1, wt)) {
         cout << "YES\n";
         cout << ff.size() << ' ';
         for (int i : ff) cout << i << ' ';
         cout << '\n';
         vector<int> ss;
         for (int j = sz - 1; j >= 0; --j) {
            if (solve(j - 1, wt - A[j])) {
               ss.push_back(A[j]);
               wt -= A[j];
            }
         }
         reverse(all(ss));
         vector<int> ans;
         int p = 0;
         for (int i = 0; i < n; ++i) {
            if (ss[p] == A[i]) {
               ans.push_back(i + 1);\
               ++p;
            }
         }
         ff = ans;
         cout << ff.size() << ' ';
         for (int i : ff) cout << i << ' ';
         cout << '\n';
         exit(0);
      }
   };

   for (int i = 1; i < sm; ++i) {
      if (dfs(n - 1, i)) {
         solve(i);
      }
   }
   cout << "NO\n";
   return 0;
}