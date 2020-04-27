#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 2e5 + 10; 

int val[N];
int tin[N];
int timer;
int sz[N];
vector<int> G[N];

void dfs(int u,int p = -1){
   tin[u] = timer++; 
   sz[u] = 1;
   for(auto &v : G[u]){
      if(v!=p){
         dfs(v,u);
         sz[u] += sz[v];
      }
   }
}

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
};


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   f(i,1,n+1){
      cin >> val[i];
   }   
   f(i,1,n){
      int u,v;
      cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
   }
   dfs(1);
   vector<int> A(n);
   f(i,1,n+1){
      A[tin[i]] = val[i]; 
   }
   FenwickTree fen(A);
   while(q--){
      int ty,s,x;
      cin >> ty;
      if(ty == 1){
         cin >> s >> x;
         fen.update(tin[s],x-fen.sum(tin[s],tin[s]));
      }else{
         cin >> s;
         cout << fen.sum(tin[s],tin[s]+sz[s]-1) << '\n';
      }
   }
   return 0;
} 