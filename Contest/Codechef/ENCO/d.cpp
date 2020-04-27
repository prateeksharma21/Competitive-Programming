#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n,k;
   cin >> n >> k;
   vector<int> A(2*n+1);
   vector<int> pre(2*n+1);
   f(i,1,n+1){
      cin >> A[i];
      A[i+n] = A[i];
   }
   f(i,1,2*n+1){
      pre[i] = pre[i-1]+A[i];
   }
   int ans = 0;
   f(i,1,n+1){
      ans = max(ans,pre[i+k-1]-pre[i-1]);
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