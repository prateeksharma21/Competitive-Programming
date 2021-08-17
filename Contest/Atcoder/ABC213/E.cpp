#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 500 + 10; 
const int M = 1e3 + 10;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
string s[N];
int vis[N][N];
int d[N][N];
vector<array<int, 2>> comp;

int valid(int x, int y) {
   return x >= 0 and y >= 0 and x < n and y < m and !vis[x][y] and s[x][y] == '.';
}

void dfs(int x, int y) {
   if (x < 0 or y < 0 or x >= n or y >= m) return;
   vis[x][y] = 1;
   comp.push_back({x, y});
   for (int i = 0; i < 4; ++i) {
      if (valid(x + dx[i], y + dy[i])) {
         dfs(x + dx[i], y + dy[i]);
      }
   }
}

int compute(vector<array<int, 2>> a, vector<array<int, 2>> b) {
   int ans = 1e9;
   for (auto [x, y] : a) {
      for (auto [n, m] : b) {
         ans = min(ans, max(abs(n - x), abs(m - y)));
      }
   }
   return (ans + 1) / 2;
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   vector<vector<array<int, 2>>> a;
   map<vector<array<int, 2>>, int> mp; 
   int id = 0, id00, idnm;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (valid(i, j)) {
            comp.clear();
            dfs(i, j);
            a.push_back(comp);
            for (auto [x, y] : comp) {
               if (x == 0 and y == 0) id00 = id;
               if (x == n - 1 and y == m - 1) idnm = id;
            }
            mp[comp] = id++;
         }
      }
   }
   debug(a, id00, idnm);
   for (int i = 0; i < id; ++i) {
      for (int j = 0; j < id; ++j) {
         d[mp[a[i]]][mp[a[j]]] = compute(a[i], a[j]);
      }
   }
   for (int k = 0; k < id; ++k) {
      for (int i = 0; i < id; ++i) {
         for (int j = 0; j < id; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
         }
      }
   }
   cout << d[id00][idnm];
   return 0;
}
