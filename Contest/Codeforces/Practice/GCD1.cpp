#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

long long dp[501][101];
long long A[501];

int32_t main(){
   int n;
   cin >> n;
   for(int i=1;i<=n;i++){
      cin >> A[i];
   }
   dp[1][A[1]]++;
   int ans = dp[1][1];
   for(int i=2;i<=n;i++){
      for(int j=i-1;j>=1;j--){
         if(A[i]>A[j]){
            for(int k=1;k<=100;k++){
               dp[i][__gcd(k*1LL,A[i])] += dp[j][k];
               dp[i][__gcd(k*1LL,A[i])] %= MOD;
            }
         }
      }
      dp[i][A[i]]++;
      ans += dp[i][1];
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
}