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
   vector<int> A(n+1);
   vector<int> pre(n+1);
   f(i,1,n+1){
      cin >> A[i];
   }
   f(i,2,n){
      pre[i] = pre[i-1]+(A[i]>A[i-1] and A[i]>A[i+1]);
   }
   vector<pii> ans;
   f(i,1,n-k+2){
      ans.pb({-pre[i+k-2]+pre[i]-1,i});
   }
   sort(all(ans));
   cout << -ans[0].F << ' ' << ans[0].S << '\n';
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
