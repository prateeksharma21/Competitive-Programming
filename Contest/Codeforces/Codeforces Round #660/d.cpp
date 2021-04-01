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
const int MOD = 1e9+7, N = 2e5 + 10; 

int A[N];
int B[N];
int deg[N];
vector<int> G[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   f(i,1,n+1){
      cin >> A[i];
   }
   f(i,1,n+1){
      cin >> B[i];
      if(B[i]!=-1){
         deg[B[i]]++;
         G[i].pb(B[i]);
      }
   }
   queue<int> q;
   f(i,1,n+1){
      if(deg[i] == 0){
         q.push(i);
      }
   }
   vector<int> v;
   vector<int> ans;
   int R = 0;
   while(!q.empty()){
      auto u = q.front();
      q.pop();
      if(A[u] < 0){
         v.pb(u);
      }else{
         R += A[u];
         ans.pb(u);
      }
      for(auto &v : G[u]){
         --deg[v];
         if(A[u] >= 0){
            A[v] += A[u];
         }
         if(deg[v] == 0){
            q.push(v);
         }
      }
   }
   for(auto u : v){
      R += A[u];
   }
   cout << R << '\n';
   for(auto &v : ans){
      cout << v << ' ';
   } 
   reverse(all(v));
   for(auto &u : v){
      cout << u << ' ';
   }
   return 0;
} 