#include<bits/stdc++.h>
using namespace std;

string T[] = {"RL","RRL","RLL","RRLL"};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--){
      int n;
      string s;
      cin >> n >> s;
      vector<vector<int>> dp(n,vector<int>(4,-1));
      
      auto match = [&](string a,string b){
         int v = 0;
         if(a.size() != b.size()) return v = 1e9;
         for(int i = 0; i < a.size(); ++i) v += (a[i] != b[i]);
         return v;
      };

      function<int(int,int)> dfs = [&](int i,int j){
         if(i > n) return (int)1e9;
         if(i == n) return 0;
         int &ans = dp[i][j];
         if(ans == -1){
            ans = 1e9;
            for(int k = 0; k < 4; ++k){
               ans = min(ans,dfs(i+(int)T[k].size(),j)+match(s.substr(i,T[k].size()),T[k]));
            }
         }
         return ans;
      };
      int R = 1e9;
      for(int i = 0; i < 4; ++i){
         R = min(R,dfs(0,i));
         s = s.substr(1)+s[0];
      }
      cout << R << '\n';
   }   
   return 0;
}