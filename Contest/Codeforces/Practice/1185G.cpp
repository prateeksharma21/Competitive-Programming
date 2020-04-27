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
const int MOD = 1e9+7, N = 1e5 + 10; 

int t[16],g[16];
int dp[1<<16][5];


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,T;
   cin >> n >> T;
   f(i,0,n){
      cin >> t[i] >> g[i];
   }
   dp[0][4] = 1;
   f(mask,0,(1<<n)){
      f(j,1,5){
         f(k,0,n){
            if(g[k]!=j and !((1<<k)&mask)){
               dp[mask^(1<<k)][g[k]] += dp[mask][j];
               dp[mask^(1<<k)][g[k]] %= MOD;
            }
         }
      }
   }
   int ans = 0;
   f(mask,0,(1<<n)){
      int sm = 0;
      f(j,0,n){
         if(mask&(1<<j)){
            sm += t[j];
         }
      }
      if(sm == T){
         f(j,1,5){
            ans += dp[mask][j];
            ans %= MOD;
         }
      }
   }
   cout << ans << '\n';
   return 0;
} 