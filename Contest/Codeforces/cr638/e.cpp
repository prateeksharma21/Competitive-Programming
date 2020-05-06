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
const int MOD = 1e9+7, N = 510; 

int n,k;
bool dp[N][N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   vector<pii> A(n+1);
   int sm_a = 0,sm_b = 0;
   f(i,1,n+1){
      cin >> A[i].F >> A[i].S;
      sm_a += A[i].F;
      sm_b += A[i].S;
   } 
   if(sm_a/k+sm_b/k == (sm_a+sm_b)/k){
      cout << sm_a/k+sm_b/k << '\n';
      return 0;
   }
   dp[0][0] = 1;
   f(i,1,n+1){
      f(j,0,k){
         dp[i][j] |= dp[i-1][(j-A[i].F%k+k)%k];
         f(l,0,min(k,A[i].F+1)){
            if((A[i].F-l)%k+A[i].S >= k){
               dp[i][j] |= dp[i-1][(j-l+k)%k];
            }
         }
      }
   }
   int mn = k-1;
   f(i,0,k){
      if(dp[n][i]){
         mn = i;
         break;
      }
   }
   cout << (sm_a+sm_b-mn)/k << '\n';
   return 0;
} 