#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 998244353, N = 5e5 + 10; 

int fact[N];

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

int nCr(int n,int r){
   if(n<r or r<0 or n<0) return 0;
   int ans = fact[n]*inv(fact[r]) % MOD;
   ans = ans*inv(fact[n-r]) % MOD;
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,k;
   fact[0] = 1;
   f(i,1,N) fact[i] = fact[i-1]*i % MOD;
   cin >> n >> k;
   int ans = 0;
   f(i,1,n+1){
      ans += nCr(n/i-1,k-1);
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
} 