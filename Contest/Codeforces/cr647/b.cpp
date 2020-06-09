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
const int MOD = 1e9+7, N = 1e6 + 10;

int n,p;
int A[N];

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
   cin >> n >> p;
   map<int,int> Cnt;
   f(i,0,n){
      cin >> A[i];
      Cnt[A[i]]++;
   }
   if(p == 1){
      cout << (n & 1) << '\n';
      return;
   }
   vector<pair<int, int>> R;
   for(auto &e : Cnt){
      R.pb(e);
   }
   reverse(all(R));
   int sz = R.size();
   int ans = 0;
   for(int i = 0; i < sz; ){
      if(R[i].S%2 == 0){
         i++;
         continue;
      }
      int need = 1,chk = 0;
      for(int j = i+1; j < sz;j++){
         int Need = need;
         int overflow = 0;
         for(int k = 1; k <= R[j-1].F-R[j].F;k++){
            Need *= p;
            if(Need > N){
               overflow = 1;
               break;
            }
         }
         if(overflow) break;
         if(R[j].S >= Need){
            R[j].S -= Need;
            i = j;
            chk = 1;
            break;
         }else{
            need = Need-R[j].S;
         }
      }
      if(!chk){
         ans = power(p,R[i].F);
         for(int j = i+1; j < sz; j++){
            ans -= ((R[j].S*power(p,R[j].F))%MOD);
            ans += MOD;
            ans %= MOD;
         }
         break;
      }
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
