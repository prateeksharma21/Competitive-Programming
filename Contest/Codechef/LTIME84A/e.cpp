#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 998244353, N = 1e6 + 1;

int Pre[N];

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
   int n;
   cin >> n;
   cout << Pre[n] << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   f(i,1,N){
      Pre[i] = Pre[i-1];
      int v = 0;      
      f(j,0,21){
         if((1ll<<j)&i){
            v = (1ll<<j);
            break;
         }
      }
      Pre[i] += power(i,v);
      Pre[i] %= MOD;
   }
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
