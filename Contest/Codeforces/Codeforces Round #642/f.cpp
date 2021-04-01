#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e2;
const int INF = 1e18;

#ifdef HOME
   #include "/home/prateek2112/print.cpp"
#else
   #define debug(...) 21
#endif

int dp[N][N];
int A[N][N];
int B[N][N];

void test(){
   int n,m;
   cin >> n >> m;
   f(i,0,n){
      f(j,0,m){
         cin >> A[i][j];
      }
   }
   int ans = INF;
   f(i,0,n){
      f(j,0,m){
         f(k,0,n){
            f(l,0,m){
               B[k][l] = dp[k][l] = INF;
            }
         }
         B[0][0] = A[i][j]-(i+j);
         if(B[0][0]>A[0][0]){
            continue;
         }
         dp[0][0] = A[0][0]-B[0][0];
         f(k,0,n){
            f(l,0,m){
               if(!k and !l) continue;
               B[k][l] = B[0][0]+k+l;
               if(B[k][l]>A[k][l]) continue;
               if(!k){
                  dp[k][l] = dp[k][l-1]+A[k][l]-B[k][l];
               }else if(!l){
                  dp[k][l] = dp[k-1][l]+A[k][l]-B[k][l];
               }else{
                  dp[k][l] = min(dp[k-1][l],dp[k][l-1])+A[k][l]-B[k][l];
               }
            }
         }
         ans = min(ans,dp[n-1][m-1]);
      }
   }
   cout << ans << '\n';
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