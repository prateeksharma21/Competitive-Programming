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
const int MOD = 998244353, N = 1e5 + 10;
 
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
   vector<int> A(n);
   map<int,int> cnt;
   f(i,0,n){
      cin >> A[i];
      cnt[A[i]]++;
   } 
   int ans = 0;
   int tot = 0;
   int earlier = 1,sm = 0;
   f(i,1,N){
      if(tot == i-1){
         int v = power(2,n-cnt[i]-sm)*earlier;
         v %= MOD;
         v *= i;
         v %= MOD;
         ans += v;
         ans %= MOD;
      }else{
         break;
      }
      tot += (cnt[i]>0);
      sm += cnt[i];
      earlier *= (power(2,cnt[i])-1+MOD);
      earlier %= MOD;
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
