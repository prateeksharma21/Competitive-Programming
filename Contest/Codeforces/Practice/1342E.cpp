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
const int MOD = 998244353, N = 2e5 + 10; 

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

int fact[N];

int nCr(int n,int r){
   if(n<r or r<0 or n<0) return 0;
   int ans = fact[n]*inv(fact[r]) % MOD;
   ans = ans*inv(fact[n-r]) % MOD;
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   fact[0] = 1;
   f(i,1,N) fact[i] = i*fact[i-1]%MOD;
   int n,k;
   cin >> n >> k;
   if(k>n-1){
      cout << "0\n";
      return 0;
   }
   int c = n-k;
   int ans = 0;
   f(i,0,c+1){
      if(i&1){
         ans -= nCr(c,i)*power(c-i,n)%MOD;
      }else{
         ans += nCr(c,i)*power(c-i,n)%MOD;
      }
      while(ans<0) ans+=MOD;
      ans %= MOD;
   }
   ans *= nCr(n,c);
   ans %= MOD;
   if(k){
      ans *= 2;
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
} 