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
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 998244353 , N = 1e5 + 10;
const int INF = 7e18+42;

int n,m;

int find(int x){
   int ans = 1;
   while(x <= INF/m and x*m <= n){
      ++ans;
      x *= m;
   }
   return ans;
}

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

void test(){
   cin >> n >> m;
   int l = 0, len = find(1);
   int ans = 0;
   int way = 1;
   while(len > 0){
      int lo = 1, hi = n;
      while(lo < hi){
         int m = (lo+hi+1)/2;
         if(find(m) < len){
            hi = m-1;
         }else{
            lo = m;
         }
      }
      int c = lo - lo/m - (l - l/m);
      if(len & 1){
         ans += (len+1)/2 * c;
      }else{
         ans += len/2 * c;
         way *= power(1+len/2,c);
         way %= MOD;
      }
      --len;
      l = lo;
   }   
   cout << ans << ' ' << way << '\n';
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
