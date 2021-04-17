#include <iostream>
#include <vector>
const int N = 3e5;

std::vector<int> g[N];
int n, x, y;
int sz[N];
int contains[N];

void compute (int u, int p = -1) {
   sz[u] = 1;
   contains[u] = (u == y);
   for (int v : g[u]) {
      if (v == p) continue;
      compute (v, u);
      sz[u] += sz[v];
      contains[u] |= contains[v];
   }
}

int main() {   
   std::ios::sync_with_stdio(false);
   std::cin.tie(NULL);
   std::cin >> n >> x >> y;
   --x, --y;
   int s = n;
   for (int i = 1; i < n; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   compute(x);
   for (int v : g[x]) {
      if (contains[v]) { 
         s -= sz[v];
      }
   }
   std::cout << n * 1LL * (n - 1) - s * 1LL * sz[y] << '\n';
}
