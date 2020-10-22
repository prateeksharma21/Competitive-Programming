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
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> h(n);
   for(int &i : h){
      cin >> i;
   }
   vector<vector<int>> To(n);
   vector<int> stk;
   stk = {0};
   for(int i = 1; i < n; ++i){
      while(!stk.empty() and h[stk.back()] > h[i]){
         stk.pop_back();
      }
      if(!stk.empty()){
         To[i].push_back(stk.back());
      }
      stk.push_back(i);
   }
   stk = {0};
   for(int i = 1; i < n; ++i){
      while(!stk.empty() and h[stk.back()] < h[i]){
         stk.pop_back();
      }
      if(!stk.empty()){
         To[i].push_back(stk.back());
      }
      stk.push_back(i);
   }
   stk = {n-1};
   for(int i = n-2; i >= 0; --i){
      while(!stk.empty() and h[stk.back()] > h[i]){
         stk.pop_back();
      }
      if(!stk.empty()){
         To[stk.back()].push_back(i);
      }
      stk.push_back(i);
   }
   stk = {n-1};
   for(int i = n-2; i >= 0; --i){
      while(!stk.empty() and h[stk.back()] < h[i]){
         stk.pop_back();
      }
      if(!stk.empty()){
         To[stk.back()].push_back(i);
      }
      stk.push_back(i);
   }
   vector<int> dp(n);
   for(int i = 1; i < n; ++i){
      dp[i] = dp[i-1]+1;
      for(int j : To[i]){
         dp[i] = min(dp[i],1+dp[j]);
      }
   }
   cout << dp[n-1] << '\n';
   return 0;
} 