#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 3e2 + 10; 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

int vis[N];
int done[N];
vector<int> G[N];
vector<int> O;

void dfs(int u){
   vis[u] = 1;
   O.pb(u);
   for(auto &v : G[u]){
      if(!vis[v]){
         dfs(v);
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> P(n+1);
   set<int> S;
   f(i,1,n+1){
      S.insert(i);
      cin >> P[i];
   }
   vector<vector<char>> A(n+1,vector<char>(n+1));
   f(i,1,n+1){
      f(j,1,n+1){
         cin >> A[i][j];
         if(A[i][j] == '1'){
            G[P[i]].pb(P[j]);
         }
      }
   }
   f(i,1,n+1){
      f(j,1,n+1) vis[j] = 0;
      O.clear();
      dfs(P[i]);
      sort(all(O));
      for(auto &e : O){
         if(!done[e]){
            done[e] = 1;
            cout << e << ' ';
            break;
         }
      }
   }
   return 0;
}