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
const int MOD = 1e9+7, N = 1e3 + 10;

int n, m;
string A[N];

void test(){
   cin >> n >> m;
   int cnt[n][2];
   memset(cnt, 0, sizeof cnt);
   for (int i = 0; i < n; ++i) {
      cin >> A[i];
      for (int j = 0; j < n; ++j) {
         if (i == j) continue;
         cnt[i][A[i][j] - 'a']++;
      }
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (i == j) continue;
         if (A[i][j] == A[j][i] or (m & 1)) {
            cout << "YES\n";
            vector<int> K = {i + 1, j + 1};
            ++m;
            int c = 0;
            while (m--) {
               cout << K[c] << ' ';
               c ^= 1;
            }
            cout << '\n';
            return;
         }
      }
   }
   if (n == 2) {
      cout << "NO\n";
      return;
   }
   int nd = -1;
   for (int i = 0; i < n; ++i) {
      if (cnt[i][0] and cnt[i][1]) {
         nd = i;
         break;
      }
   }
   assert(nd != -1);
   if (nd == -1) {
      cout << "NO\n";
      return;
   }
   cout << "YES\n";   
   vector<int> R[2];
   for(int j = 0; j < n; ++j) {
      if (j == nd) continue;
      R[A[nd][j] - 'a'].push_back(j + 1);
   }
   vector<int> K;
   if (m % 4 == 0) {
      K = {nd + 1, R[0].back(), nd + 1, R[1].back()};
      ++m;
      int c = 0;
      while (m--) {
         cout << K[c] << ' ';
         c = (c + 1) % 4;
      }
   } else {
      K = {R[0].back(), nd + 1, R[1].back(), nd + 1};
      ++m;
      int c = 0;
      while (m--) {
         cout << K[c] << ' ';
         c = (c + 1) % 4;
      }
   }
   cout << '\n';
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