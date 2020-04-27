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
   int ans = 0;
   f(i,k,n+2){
      ans += 1+n*(n+1)/2-(n-i)*(n-i+1)/2-(i-1)*i/2;
      ans %= MOD;
      // cout << ans << '\n';
      while(ans<0) ans += MOD;
   }
   cout << ans << '\n';
   return 0;
}