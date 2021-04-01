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
const int MOD = 1e9+7, N = 2e5 + 10;
const int INF = 1e15;

int n, m;
vector<int> g[N];
int d[N];
int used[N];
int dp1[N];
int dp2[N];

void bfs (int s = 1) {
   queue<int> q;
   q.push(s);
   used[s] = true;
   d[s] = 0;
   while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : g[v]) {
         if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
         }
      }
   }
}

int compute_dp1(int u) {
   int &ans = dp1[u];
   if (ans != -1) return ans;
   ans = d[u];
   for (int v : g[u]) {
      if (d[v] > d[u]) {
         ans = min(ans, compute_dp1(v));
      }
   }
   return ans;
}

int compute_dp2(int u) {
   int &ans = dp2[u];
   if (ans != -1) return ans;
   ans = d[u];
   for (int v : g[u]) {
      if (d[v] > d[u]) {
         ans = min(ans, compute_dp2(v));
      } else {
         ans = min(ans, compute_dp1(v));
      }
   }
   return ans;
}

void test(){
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
      g[i].clear();
      dp1[i] = -1;
      dp2[i] = -1;
      used[i] = false;
      d[i] = 0;
   }
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
   }
   bfs();
   for (int i = 1; i <= n; ++i) {
      cout << compute_dp2(i) << ' ';
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