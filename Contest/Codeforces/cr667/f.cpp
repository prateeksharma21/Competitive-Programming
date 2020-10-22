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
const int MOD = 1e9+7, N = 2e2 + 10; 
const int INF = -1e15;

int dp[N][N][N];
int vis[N][N][N];
int suff[N][26];
int n,k;
string s,t;
int a,b;

int dfs(int i,int r,int c){
   if(r < 0) return INF;
   if(i == n+1){
      if(r == 0){
         return 0;
      }else{
         return INF;
      }
   }
   if(vis[i][r][c]) return dp[i][r][c];
   vis[i][r][c] = 1;
   int &ans = dp[i][r][c];
   if(s[i-1] == t[0]){
      ans = dfs(i+1,r,c+1)+suff[i+1][b];
      ans = max(ans,dfs(i+1,r-1,c));
      ans = max(ans,dfs(i+1,r-1,c)+c);
   }else if(s[i-1] == t[1]){
      ans = dfs(i+1,r-1,c+1)-c+suff[i+1][b];
      ans = max(ans,dfs(i+1,r,c));
      ans = max(ans,dfs(i+1,r-1,c));
   }else{
      ans = dfs(i+1,r-1,c+1)+suff[i+1][b];
      ans = max(ans,dfs(i+1,r-1,c)+c);
      ans = max(ans,dfs(i+1,r,c));
   }
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   cin >> s >> t;
   for(int i = n; i >= 1; --i){
      for(int j = 0; j < 26; ++j){
         suff[i][j] = suff[i+1][j];
      }
      suff[i][s[i-1]-'a']++;
   }
   a = t[0]-'a';
   b = t[1]-'a';
   if(a == b){
      int have = 0;
      int cur = 0;
      for(int i = 0; i < n; ++i){
         if(s[i] != t[0]){
            have++;
         }else{
            cur++;
         }
      }
      cur += min(have,k);
      cout << cur*(cur-1)/2 << '\n';
      return 0;
   }
   int ans = 0;
   for(int i = 0; i <= k; ++i){
      ans = max(ans,dfs(1,i,0));
   }
   cout << ans << '\n';
   return 0;
} 