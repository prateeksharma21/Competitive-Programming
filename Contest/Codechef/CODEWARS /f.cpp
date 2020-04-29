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

long long power(long long x,long long y){
   long long ans=1;
   x %= MOD;
   if(y < 0) return 0;
   while(y){
      if(y & 1) ans = (ans*x) %MOD;
      x = x*x % MOD;
      y /= 2;
   }
   return ans;
}
 
long long inv(long long x){
   return power(x,MOD-2);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--){
      int n;
      cin >> n;
      if(n<=2){
         cout << "0\n";
         continue;
      }
      int v = (n+1)/2;
      int ans = v*inv(n);
      ans %= MOD;
      cout << ans << '\n';
   }
   return 0;
} 