#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 2e5 + 10; 


#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif


int a[N],b[N],c[N];
int n;
int sz[N];
int C01[N],C10[N];
int tin[N];
int timer = 0;
vector<int> G[N];
int ans = 0;
int parent[N];

struct FenwickTree{
   int n;
   vector<ll> fenw;

   FenwickTree(int n){
      this->n = n;
      fenw.assign(n,0);
   }

   FenwickTree(vector<ll> a) : FenwickTree((int)a.size()){
      f(i,0,(int)a.size()){
         update(i,a[i]);
      }
   }

   ll sum(int r){
      ll res = 0;
      while(r>=0){
         res += fenw[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }

   ll sum(int l,int r){
      return sum(r)-sum(l-1);
   }

   void update(int ind,ll val){
      while(ind<n){
         fenw[ind] += val;
         ind = ind | (ind+1);
      }
   }

   void range_add(int l, int r, int val) {
       update(l, val);
       update(r + 1, -val);
   }

};


void dfs(int u,int p){
   sz[u] = 1;
   parent[u] = p;
   tin[u] = timer++;
   if(c[u] == 0 and b[u] == 1){
      C10[u]++;
   }
   if(c[u] == 1 and b[u] == 0){
      C01[u]++;
   }
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u);
         sz[u] += sz[v];
         C10[u] += C10[v];
         C01[u] += C01[v];
      }
   }
}

int D[N];

void dfs(int u){
   if(D[u]) return;
   D[u] = 1;
   for(auto &v : G[u]){
      if(v!=parent[u]){
         dfs(v);
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   int c1 = 0,c2 = 0;
   f(i,1,n+1){
      cin >> a[i] >> b[i] >> c[i];
      c1 += b[i];
      c2 += c[i];
   }
   if(c1 != c2){
      cout << "-1\n";
      return 0;
   }
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   dfs(1,0);
   vector<pair<int, int>> A(n+1);
   f(i,1,n+1){
      A[i] = {a[i],i};
   }
   sort(all(A));
   FenwickTree fen(timer);
   int ans = 0;
   f(i,1,n+1){
      int u = A[i].S;
      if(D[u]) continue;
      int done = fen.sum(tin[u],tin[u]+sz[u]-1);
      int K = 2*min(C10[u],C01[u]);
      K -= done;
      ans += K*A[i].F;
      dfs(u);
      fen.update(tin[u],K);
   }
   cout << ans << '\n';
   return 0;
} 