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
const int MOD = 1e9+7, N = 2e5 + 10; 

int dp[N];
int p[N];
int t[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<pii> A(n);
   f(i,1,n+1){
      dp[i] = MOD;
      p[i] = -1;
      cin >> A[i-1].F;
      A[i-1].S = i-1;
   }
   sort(all(A));
   f(i,0,n){
      for(int j=3;j<=5 and i+j<=n;j++){
         int d = A[i+j-1].F-A[i].F;
         if(dp[i+j] > dp[i]+d){
            p[i+j] = i;
            dp[i+j] = dp[i]+d;
         }
      }
   }
   int cur = n;
   int cnt = 0;
   while(cur){
      for(int i=cur-1;i>=p[cur];i--){
         t[A[i].S] = cnt;
      }
      cnt++;
      cur = p[cur];
   }
   cout << dp[n] << ' ' << cnt << '\n';
   f(i,0,n){
      cout << t[i]+1 << ' ';
   }
   cout << '\n';
   return 0;
}