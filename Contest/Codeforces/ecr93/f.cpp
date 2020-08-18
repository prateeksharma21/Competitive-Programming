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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e6 + 10; 

int cnt[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   string s;
   cin >> n >> s;
   int z = -1,o = -1;
   for(int i = 0; i < n; ++i){
      if(s[i] == '0'){
         z = i;
      }
      if(s[i] == '1'){
         o = i;
      }
      cnt[i] = i-min(z,o);
   }
   for(int i = 1; i <= n; ++i){
      int idx = 0;
      int ans = 0;
      while(idx < n){
         if(cnt[idx] >= i){
            ans++;
            idx += i;
         }else{
            idx += i-cnt[idx];
         }
      }
      cout << ans << ' ';
   }
   return 0;
}