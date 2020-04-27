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
 
void test(){
   int n,k;
   cin >> n >> k;
   if(n == 0){
      int ans = (k-1)*(k-1)+k-1;
      ans += MOD;
      ans %= MOD;
      cout << ans << '\n';
      return;
   }
   int row = n+(k+1)/2-1;
   int ans = row*row % MOD;
   int cur = row;
   if(k & 1){
      ans += cur-n+1;
   }else{
      ans += cur+1+n;
   }
   ans %= MOD;
   ans--;
   ans += MOD;
   ans %= MOD;
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
