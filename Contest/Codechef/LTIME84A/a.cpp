#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

void test(){
   int n;
   cin >> n;
   vector<int> A(3*n);
   int cnt = 0;
   f(i,0,n){
      cin >> A[i];
      A[i+n] = A[i];
      A[i+2*n] = A[i];
      cnt += (A[i] == 0);
   }
   if(cnt == n-1){
      cout << "-1\n";
      return;
   }
   vector<int> pos,vis(n);
   f(i,0,n){
      if(A[i] == 1){
         pos.pb(i);
      }
   }
   vector<set<int>> G(n);
   int sz = pos.size();

   f(i,0,sz){
      int prv = pos[(i-1+sz)%sz];
      int nxt = pos[(i+1)%sz];
      int ii = i;
      i = pos[i];
      if(prv>=i){
         if(abs(i+n-prv)<abs(i-nxt)){
            G[i].insert(prv);
            G[prv].insert(i);
         }else{
            G[i].insert(nxt);
            G[prv].insert(i);
         }
      }else if(nxt<=i){
         if(abs(i-prv)<abs(i-nxt-n)){
            G[i].insert(prv);
            G[prv].insert(i);
         }else{
            G[i].insert(nxt);
            G[prv].insert(i);
         }
      }else{
         if(abs(i-prv)<abs(i-nxt)){
            G[i].insert(prv);
            G[prv].insert(i);
         }else{
            G[i].insert(nxt);
            G[prv].insert(i);
         }
      }
      i = ii;
   }

   vector<int> o;

   function<void(int)> dfs = [&](int u){
      vis[u] = 1;
      o.pb(u);
      for(auto &v : G[u]){
         if(!vis[v]){
            dfs(v);
         }
      }
   };

   int R = 0;
   // debug(G);

   f(i,0,n){
      if(!vis[i]){
         o.clear();
         dfs(i);
         sort(all(o));
         int mn = o.front(),mx = o.back();
         int v = 1e18;
         // debug(mn,mx);
         f(i,mn,mx+1){
            int ans = 0;
            for(auto &e : o){
               ans += min(abs(e-i),abs(e+n-i));
            }
            v = min(v,ans);
         }
         R += v;
      }
   }
   cout << R << '\n';
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