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
const int MOD = 163577857, N = 1e5 + 10;
 
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
int in[N];

int nCr(int n,int r){
   if(r>n or r<0 or n<0) return 0;
   int ans = fact[n]*in[r] % MOD;
   ans = ans*in[n-r] % MOD;
   return ans;
}

void test(){
   int n;
   cin >> n;
   map<int,int> cnt;
   vector<int> A(n);
   f(i,0,n){
      cin >> A[i];
      cnt[A[i]]++;
   } 
   int pw = power(2,cnt[0]);
   for(int i=-n;i<=n;i++){
      int ans = pw*nCr(cnt[1]+cnt[-1],cnt[1]+abs(i));
      ans %= MOD;
      if(!i){
         ans += MOD-1;
         ans %= MOD;
         cnt[1] = cnt[1]^cnt[-1];
         cnt[-1] =  cnt[1]^cnt[-1];
         cnt[1] = cnt[1]^cnt[-1];
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
   fact[0] = 1;
   in[0] = inv(1);
   f(i,1,N){
      fact[i] = i*fact[i-1]%MOD;
      in[i] = inv(fact[i]);
   }
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
