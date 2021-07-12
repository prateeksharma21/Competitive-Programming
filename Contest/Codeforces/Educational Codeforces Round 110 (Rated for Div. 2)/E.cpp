#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")             //Enable AVX

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
const int MOD = 1e9+7, N = 3e5 + 10; 
const int LG = log2(N) + 1;

int q, a1, c1;
int Gold[N], Cost[N];
int remGold[N];
int parent[N][LG];
int depth[N];
int pre[N];

int kth(int u,int d){
   for(int j=LG-1;j>=0;j--){
      if((1ll<<j)<=d){
         u = parent[u][j];
         d -= (1ll<<j);
      }
   }
   return u;
}

void add(int u, int p, int gold, int cost) {
   parent[u][0] = p;
   for (int k = 1; k < LG; ++k) {
      parent[u][k] = parent[parent[u][k - 1]][k - 1];
   }
   depth[u] = depth[p] + 1;
   Gold[u] = remGold[u] = gold;
   Cost[u] = cost;
   pre[u] = pre[p] + gold;
}

void find(int u, int req) {
   int cur = u;

   for (int i = LG - 1; i >= 0; --i) {
      if (parent[u][i] == 0) continue;
      int p = parent[u][i];
      if (remGold[p] != 0) {
         u = p;
      }
   }

   assert(remGold[parent[u][0]] == 0);

   int dist = depth[cur] - depth[u];
   int diff = Gold[u] - remGold[u];
   int l = 0, r = dist;
   int pr = parent[u][0];
   int ans = -1;

   while (l <= r) {
      int m = (l + r) / 2;
      int par = kth(cur, m);
      if (pre[par] - pre[pr] - diff >= req) {
         l = m + 1;
         ans = par;
      } else {
         r = m - 1;
      }
   }

   if (ans == -1) {
      int price = 0;
      int gold = 0;
      while (remGold[cur]) {
         gold += remGold[cur];
         price += remGold[cur] * Cost[cur];
         remGold[cur] = 0;
         cur = parent[cur][0];
      }
      cout << gold << ' ' << price << '\n';
      return;
   }

   int have = pre[ans] - pre[pr] - diff;
   int extra = have - req;
   int middle = ans;
   int price = 0;

   while (remGold[ans]) {
      // debug(ans);
      price += remGold[ans] * Cost[ans];
      remGold[ans] = 0;
      ans = parent[ans][0];
   }
   // debug(price, remGold[1]);
   price -= extra * Cost[middle];
   remGold[middle] = extra;
   cout << req << ' ' << price << '\n';
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> q >> a1 >> c1;
   Cost[1] = c1;
   Gold[1] = remGold[1] = a1;
   pre[1] = a1;
   for (int i = 2; i <= q + 1; ++i) {
      int ty;
      cin >> ty;
      if (ty == 1) {
         int p, a, c;
         cin >> p >> a >> c;
         ++p;
         add(i, p, a, c);
      } else {
         int v, w;
         cin >> v >> w;
         ++v;
         find(v, w);
      }
   }
   return 0;
}