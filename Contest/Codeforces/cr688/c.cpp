#ifdef Prateek
  #include "\Prateek.h"
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
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

vector<int> solve(vector<vector<int>> A) {
   int n = A.size();
   vector<int> lst(10, -1), fst(10, 1e9);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         lst[A[i][j]] = max(lst[A[i][j]], j);
         fst[A[i][j]] = min(fst[A[i][j]], j);
      }
   }
   // debug(lst, fst);
   vector<int> R;
   for (int k = 0; k < 10; ++k) {
      int ans = 0;
      if (lst[k] == -1) {
         R.push_back(ans);
         continue;
      }
      for (int i = 0; i < n; ++i) {
         vector<int> occ;
         for (int j = 0; j < n; ++j) {
            if (A[j][i] == k) {
               occ.push_back(j);
            }
         }
         if (occ.empty()) continue;
         // debug(k, occ);
         int fr = occ.front();
         ans = max(ans, max(fr, n - 1 - fr) * max(abs(lst[k] - i), abs(i - fst[k])));
         int bk = occ.back();
         ans = max(ans, max(bk, n - 1 - bk) * max(abs(lst[k] - i), abs(i - fst[k])));
         ans = max(ans, (bk - fr) * max(i, n - 1 - i));
      }
      R.push_back(ans);
   }
   return R;
}

void test(){
   int n;
   cin >> n;
   vector <string> s(n);
   vector <vector <int>> A(n, vector<int>(n));
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (int j = 0; j < n; ++j) {
         A[i][j] = s[i][j] - '0';
      }
   }
   vector<int> a = solve(A);
   for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
         swap(A[i][j],A[j][i]);
      }
   }
   // debug(a);
   vector<int> b = solve(A);
   for (int i = 0; i < 10; ++i) {
      cout << max(a[i], b[i]) << ' ';
   }
   cout << '\n';
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
