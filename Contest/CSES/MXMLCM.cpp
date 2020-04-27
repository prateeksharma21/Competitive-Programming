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

ll power(ll x, ll y){
   ll ans=1;
   if(y==1) return x%MOD;
   x=x % MOD,y=y % (MOD-1);
   while(y){
      if(y & 1) ans = (ans*x) %MOD;
      x *= x;
      x = x % MOD;
      y >>= 1;
   }
   return ans;
}
 
ll inv(ll x){
   return power(x,MOD-2);
}

void test(){
   int n,m;
   cin >> n >> m;
   vector<int> a(n+1);
   vector<int> cnt(m+1);
   f(i,1,n+1){
      cin >> a[i];
      for(int j=2;j*j<=a[i];j++){
         int c = 0;
         while(a[i]%j == 0){
            a[i] /= j;
            c++;
         }
         cnt[j] = max(cnt[j],c);
      }
      if(a[i]>1){
         cnt[a[i]] = max(cnt[a[i]],1ll);
      }
   }
   int ans = 1,v = 1;
   f(i,2,m+1){
      int res = 1;
      int x = i;
      for(int j=2;j*j<=x;j++){
         int c = 0;
         while(x%j == 0){
            x/=j;
            c++;
         }
         res = res*power(j,max(c-cnt[j],0ll));
      }
      if(x>1){
         if(cnt[x] == 0){
            res = res*x;
         }
      }
      if(res>ans){
         ans = res;
         v = i;
      }
   }
   cout << v << '\n';
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