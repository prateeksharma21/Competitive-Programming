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
   int a,b,q;
   cin >> a >> b >> q;
   int mx = max(a,b);
   int lc = (a*b)/__gcd(a,b);
   while(q--){
      int l,r;
      cin >> l >> r;
      int ans = r-l+1;
      f(i,0,mx){
         int ff = (l+lc-1)/lc;
         int ss = (r/lc);
         ans -= (ss-ff+1);
         l--;
         r--;
         if(l<0 and r<0) break;
         l = max(l,0ll);
         r = max(r,0ll);
      }
      cout << ans << ' ';
   }
   cout << '\n';
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