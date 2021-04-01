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

bool can(vector<vector<int>> a) {
   int n = a.size();
   vector<int> row(n), col(n);
   
   set<array<int, 2>> R[n], C[n];
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (a[i][j] == -1) {
            row[i]++;
            col[j]++;
            R[i].insert({i, j});
            C[j].insert({i, j});
         }
      }
   }

   set<array<int, 3>> s;

   for (int i = 0; i < n; ++i) {
      s.insert({row[i], 0, i});
      s.insert({col[i], 1, i});
   }

   while (!s.empty()) {
      auto [val, what, num] = *s.begin();
      if (val == 0) {
         s.erase(s.begin());
         continue;
      }
      if (val > 1) {
         break;
      }
      s.erase(s.begin());
      if (what == 0) {
         auto [i, j] = *R[num].begin();
         R[num].clear();
         s.erase({col[j], 1, j});
         --col[j];
         C[j].erase({i, j});
         s.insert({col[j], 1, j});
      } else {
         auto [i, j] = *C[num].begin();
         C[num].clear();
         s.erase({row[i], 0, i});
         --row[i];
         R[i].erase({i, j});
         s.insert({row[i], 0, i});
      }
   }
   return s.empty();
}

void test(){
   int n;
   cin >> n;
   auto a = vector(n, vector(n, 0LL));
   vector<array<int, 2>> pts;
   vector<int> row(n), col(n);
   int total = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
         if (a[i][j] == -1) {
            row[i]++;
            ++total;
            col[j]++;
            pts.push_back({i, j});
         }
      }
   }
   vector<int> K(pts.size());
   iota(all(K), 0);
   auto b = a;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> b[i][j];
      }
   }
   vector<int> r(n), c(n);
   for (int &i : r) cin >> i;
   for (int &i : c) cin >> i;
   
   int mn = 1e18;
   
   function<void(vector<vector<int>>, int, int, vector<array<int, 2>>)> solve = [&] (vector<vector<int>> a, int rem, int cst, vector<array<int, 2>> pts) {
      if (rem == 0) {
         if (can(a)) {
            mn = min(mn, cst);
         } 
         return;
      }
      auto [i, j] = pts.back();
      pts.pop_back();
      solve(a, rem - 1, cst, pts);
      a[i][j] = 1;
      solve(a, rem - 1, cst + b[i][j], pts);
   };

   solve(a, total, 0, pts);

   cout << mn << '\n';
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