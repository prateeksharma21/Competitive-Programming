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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 200 + 10; 

int dp[N][N][N];
int vis[N][N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int R,G,B;
   cin >> R >> G >> B;
   vector<int> r(R+1),g(G+1),b(B+1);
   for(int i = 0; i < R; ++i){
      cin >> r[i+1];
   }
   for(int i = 0; i < G; ++i){
      cin >> g[i+1];
   }
   for(int i = 0; i < B; ++i){
      cin >> b[i+1];
   }
   sort(all(r));
   sort(all(g));
   sort(all(b));

   function<int(int,int,int)> dfs = [&](int rr,int gg,int bb){

      if(vis[rr][gg][bb]) return dp[rr][gg][bb];

      int &ans = dp[rr][gg][bb];
      vis[rr][gg][bb] = 1;

      if(rr > 0 and gg > 0){
         ans = max(ans,r[rr]*g[gg]+dfs(rr-1,gg-1,bb));
      }

      if(rr > 0 and bb > 0){
         ans = max(ans,r[rr]*b[bb]+dfs(rr-1,gg,bb-1));
      }

      if(gg > 0 and bb > 0){
         ans = max(ans,g[gg]*b[bb]+dfs(rr,gg-1,bb-1));
      }

      return ans;
   };


   cout << dfs(R,G,B) << '\n';
   return 0;
} 