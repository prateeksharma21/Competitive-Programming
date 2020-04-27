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
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   } 
   vector<int> upd(2*k+2);
   f(i,0,n/2){
      int sm = a[i]+a[n-i-1];
      int mn = min(a[i],a[n-i-1]);
      int d = k-mn;
      upd[sm+1]++;
      upd[sm+d+1]--;
      upd[sm+d+1] += 2;
      upd[2*k+1] += 2;

      int mx = max(a[i],a[n-i-1]);
      d = mx-1;
      upd[sm]--;
      upd[sm-d]++;
      upd[2]+=2;
      upd[sm-d]-=2;
   }
   int cur = 0;
   int ans = 1e18;
   f(i,2,2*k+1){
      cur += upd[i];
      ans = min(ans,cur);
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
