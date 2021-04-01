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
const int MOD = 1e9+7, N = 3e5 + 10;
 
void test(){
   int n;
   cin >> n;
   vector<pii> a(n);
   f(i,0,n){
      cin >> a[i].F >> a[i].S;
   } 
   int ans = a[0].F,dmg = a[0].S;
   f(i,1,n){
      int x = a[i].F-dmg;
      dmg = a[i].S;
      ans += max(0ll,x);
   }
   int res = ans;
   // cout << res << '\n';
   f(i,1,n){
      ans = ans-a[i-1].F-max(a[i].F-a[i-1].S,0ll)+a[i].F+max(a[i-1].F-a[(i-2+n)%n].S,0ll);
      res = min(res,ans);
      // cout << ans << '\n';
   }
   cout << res << '\n';
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
