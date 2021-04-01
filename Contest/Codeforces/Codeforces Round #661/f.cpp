#include <bits/stdc++.h>
using namespace std;
const int N = 3001;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--){
      int n;
      cin >> n;
      map<int,int> mp;
      vector<int> l(n),r(n);
      for(int i = 0; i < n; ++i){
         cin >> l[i] >> r[i];
         mp[l[i]];
         mp[r[i]];
      }
      int c = 0;
      for(auto &e : mp){
         e.second = c++;
      }
      vector<int> G[c];
      for(int i = 0; i < n; ++i){
         l[i] = mp[l[i]];
         r[i] = mp[r[i]];
         G[l[i]].push_back(r[i]);
      }

      vector<vector<int>> dp(c,vector<int>(c));
      vector<vector<bool>> vis(c,vector<bool>(c));

      function<int(int,int)> dfs = [&](int l,int r){
         if(l > r) return 0;
         if(vis[l][r]) return dp[l][r];
         int &ans = dp[l][r];
         vis[l][r] = 1;
         int f = count(G[l].begin(),G[l].end(),r);
         ans = max(ans,f+dfs(l+1,r));
         for(int i = l+1; i <= r; ++i){
            ans = max(ans,f+dfs(l,i)+dfs(i+1,r));
         }
         return ans;
      };

      cout << dfs(0,c-1) << '\n';
   }   
   return 0;
}
