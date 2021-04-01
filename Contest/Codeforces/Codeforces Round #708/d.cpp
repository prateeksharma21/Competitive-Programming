#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 5e3 + 10;

int T[N];
int s[N];
int64_t dp[N];

void test(){
   int n;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      cin >> T[i];
   }   

   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }

   vector<int> Mn, Mx, type;

   for (int i = 0, j = 0; i < n; i = j) {
      while (j < n and T[i] == T[j]) ++j;
      int mx = -1e9, mn = 1e9;
      for (int k = i; k < j; ++k) {
         mn = min(mn, s[k]);
         mx = max(mx, s[k]);
      }
      Mn.push_back(mn);
      Mx.push_back(mx);
      type.push_back(T[i]);
   }

   n = Mn.size();

   auto get = [&](int i, int j) {
      return max({abs(Mx[i] - Mn[j]),abs(Mx[i] - Mx[j]),abs(Mn[i] - Mn[j]),abs(Mn[i] - Mx[j])});
   };

   for (int i = n - 1; i >= 0; --i) {
      dp[i] = 0;
      if (i + 1 < n) {
         dp[i] = dp[i + 1] + get(i, i + 1);
      }
      for (int j = i - 2; j >= 0; --j) {
         if (type[i] != type[j]) {
            int64_t v = get(i, j);
            if (i + 1 < n) {
               v += get(j, i + 1);
               if (i + 2 < n) {
                  v += dp[i + 2];
               }
            }
            dp[i] = max(dp[i], v);
         }
      }
   }

   cout << *max_element(dp, dp + n) << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}