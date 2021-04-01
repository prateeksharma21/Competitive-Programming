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
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   string s;
   int x;
   cin >> s >> x;
   int n = s.length();
   string ans(n,'1');
   for(int i = 0; i < n; ++i){
      if(s[i] == '0'){
         if(i-x >= 0){
            ans[i-x] = '0';
         }
         if(i+x < n){
            ans[i+x] = '0';
         }
      }
   }
   string gen(n,'0');
   for(int i = 0; i < n; ++i){
      if(i-x>=0 and i+x<n){
         if(ans[i-x] == '0' and ans[i+x] == '0'){
            gen[i] = '0';
         }else{
            gen[i] = '1';
         }
      }else if(i-x>=0){
         gen[i] = ans[i-x];
      }else if(i+x<n){
         gen[i] = ans[i+x];
      }else{
         gen[i] = '0';
      }
   }
   debug(gen,ans);
   if(gen == s){
      cout << ans << '\n';
   }else{
      cout << "-1\n";
   }
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
