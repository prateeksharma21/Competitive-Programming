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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 2e5 + 10; 

vector<int> g[N];
vector<int> ng[N];
int vis[N];
int leader[N];
int parent[N];
int mark[N];
int sz[N];
int done;
int len = 0;
vector<int> comp;

void dfs (int u, int p) {
   vis[u] = 1;
   parent[u] = p;
   for (int v : g[u]) {
      if (v != p) {
         if (vis[v] and !done) {
            int k = u;
            vector <int> p1;
            while (k) {
               p1.push_back(k);
               k = parent[k];
            }
            k = v;
            vector<int> p2;
            while (k) {
               p2.push_back(k);
               k = parent[k];
            }
            int ans = p1.size() + p2.size();
            reverse(all(p1));
            reverse(all(p2));
            int i;
            for (i = 0; i < min(p1.size(), p2.size()); ++i) {
               if (p1[i] == p2[i]) {
                  ans -= 2;
               } else {
                  mark[p1[i]] = 1;
                  mark[p2[i]] = 1;
                  mark[p1[i-1]] = 1;
               }
            }
            mark[p1[i-1]] = 1;
            int j = i;
            while (i < p1.size()) {
               mark[p1[i]] = 1;
               ++i;
            }
            while (j < p2.size()) {
               mark[p2[i]] = 1;
               ++j;
            }

            ++ans;
            len = ans;
            done = 1;
         } else {
            if (!vis[v])
            dfs(v, u);
         }
      }
   }
}

void dfs1(int u, int p = 0) {
   sz[u] = 1;
   vis[u] = 1;
   comp.push_back(u);
   for (int v : ng[u]) {
      if (v != p) {
         dfs1(v, u);
         sz[u] += sz[v];
      }
   }
}

void solve() {
   int n;
   cin >> n;
   len = 0;
   done = false;
   for (int i = 1; i <= n; ++i) {
      g[i].clear();
      vis[i] = 0;
      mark[i] = 0;
      parent[i] = 0;
      sz[i] = 0;
      ng[i].clear();
      leader[i] = 0;
   }
   for (int i = 0; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dfs(1,0);
   for (int i = 1; i <= n; ++i) {
      if (mark[i]) {
         debug(i);
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j : g[i]) {
         if(!(mark[i] and mark[j])) {
            debug(i, j);
            ng[i].push_back(j);
         }
      }
      debug(ng[i]);
      vis[i] = 0;
   }
   for (int i = 1; i <= n; ++i) {
      if (mark[i] and !vis[i]) {
         comp.clear();
         dfs1(i);
         for (int v : comp) {
            leader[v] = i;
         }  
         debug(i, comp);
      }
   }
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      ans += (n - sz[leader[i]]);
   }
   ans /= 2;
   ans += (n * (n-1))/2;
   cout << ans << '\n';
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while (tt--) {
      solve();
   }
   return 0;
} 