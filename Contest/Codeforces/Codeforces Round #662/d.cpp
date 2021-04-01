#include<bits/stdc++.h>
using namespace std;
const int N = 2010;

int dp[N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   vector<vector<char>> A(n,vector<char>(m));
   for(int i = 0 ; i < n; ++i){
      for(int j = 0; j < m; ++j){
         cin >> A[i][j];
      }
   }
   for(int i = 0; i < n; ++i){
      dp[i][0] = dp[i][m-1] = 1;
   }
   for(int i = 0; i < m; ++i){
      dp[0][i] = dp[n-1][i] = 1;
   }
   int R = 0;
   for(int i = 1; i < n; ++i){
      for(int j = 1; j < m-1; ++j){
         int bst = min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
         if(A[i-1][j-1] == A[i][j] and A[i-1][j] == A[i][j] and A[i-1][j+1] == A[i][j]){
            if(i - 2*bst >= 0 and A[i-2*bst][j] == A[i][j]){
               dp[i][j] = bst+1;
            }else{
               dp[i][j] = bst;
            }
         }else{
            dp[i][j] = 1;
         }
      }
   }
   for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
         R += dp[i][j];
      }
   }

   cout << R << '\n';
   return 0;
}