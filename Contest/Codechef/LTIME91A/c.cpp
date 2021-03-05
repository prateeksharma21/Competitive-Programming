#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve3 (vector<int> a) {
   int n = a.size();
   vector<vector<int>> dp(n, vector<int>(2,-1));
   for (int i = 0; i < n; ++i) {
      dp[i][1] = 1;
   }
   vector<int> mx0(n + 1);
   vector<int> mx1(n + 1);
   int mx = 0;
   for (int i = n - 1; i >= 0; --i) {
      if (mx1[a[i]]) {
         dp[i][0] = mx1[a[i]] + 1;
      }
      dp[i][1] = max(dp[i][1], mx + 1);
      mx1[a[i]] = max(mx1[a[i]], dp[i][1]);
      mx = max(mx, dp[i][0]);
      // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
   }

   int ans = n;
   for (int i = 0; i < n; ++i) {
      if (dp[i][0] != -1) {
         ans = min(ans, n - dp[i][0]);
      }
   }
   cout << ans << '\n';
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      cin >> n;
      vector <int> a(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      // int chk = 1;
      // for (int i = 1; i < n; ++i) {
      //    chk &= (a[i] >= a[i - 1]);
      // }
      // if (chk) {
      //    int ans = 0;
      //    for (int i = 0, j = 0; i < n; i = j) {
      //       while (j < n and a[i] == a[j]) ++j;
      //       if ((j - i) & 1) {
      //          ++ans;
      //       }
      //    }
      //    cout << ans << '\n';
      //    continue;
      // }

      // if (n <= 3000) {
         solve3(a);
         continue;
      // }


      int ans = n;
      for (int i = 0; i < (1 << n); ++i) {
         int c = 0;
         vector<int> r;
         for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) {
               ++c;
            } else {
               r.push_back(a[j]);
            }
         }
         int sz = r.size();
         if (sz & 1) continue;
         int chk = 1;
         for (int i = 0; i < sz; i += 2) {
            if (r[i] != r[i + 1]) {
               chk = 0;
               break;
            }
         }
         if (chk) {
            ans = min(ans, c);
         }
      }
      cout << ans << '\n';
   }
   return 0;
}