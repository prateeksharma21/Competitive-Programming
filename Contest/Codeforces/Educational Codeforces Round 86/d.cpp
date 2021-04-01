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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,k;
   cin >> n >> k;
   vector<int> A(n);
   vector<int> cnt(k+1);
   f(i,0,n){
      cin >> A[i];
      cnt[A[i]]++;
   }
   vector<int> C(k+1);
   f(i,1,k+1){
      cin >> C[i];
   }
   for(int i=k-1;i>=1;--i){
      cnt[i] += cnt[i+1];
   }
   int ans = 1;
   f(i,1,k+1){
      ans = max(ans,(cnt[i]+C[i]-1)/C[i]);
   }
   cout << ans << '\n';
   vector<vector<int>> R(ans);
   sort(A.begin(),A.end());
   f(i,0,n){
      R[i%ans].pb(A[i]);
   }
   f(i,0,ans){
      cout << R[i].size() << ' ';
      for(auto &e : R[i]){
         cout << e << ' ';
      } 
      cout << '\n';
   }
   return 0;
}