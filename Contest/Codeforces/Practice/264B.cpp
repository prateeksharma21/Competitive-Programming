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

vector<int> F[N];
int V[N];
int dp[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   f(i,2,N){
      for(int j=i;j<N;j+=i){
         F[j].pb(i);
      }
   }
   int n;
   cin >> n;
   vector<int> A(n+1);
   f(i,1,n+1){
      cin >> A[i];
      int v = 0;
      for(auto &ff : F[A[i]]){
         v = max(v,V[ff]);
      }
      dp[i] = v+1;
      for(auto &ff : F[A[i]]){
         V[ff] = max(V[ff],dp[i]);
      }
   } 
   cout << *max_element(dp+1,dp+n+1) << '\n';

   return 0;
} 