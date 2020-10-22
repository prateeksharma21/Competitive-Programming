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
   int n;
   cin >> n;
   string s;
   cin >> s;
   if(n & 1){
      int chk = 0;
      for(int i = 0; i < n; i += 2){
         chk |= ((s[i]-'0') & 1);
      }
      if(chk){
         cout << "1\n";
      }else{
         cout << "2\n";
      }
   }else{
      int chk = 0;
      for(int i = 1; i < n; i += 2){
         chk |= ((s[i]-'0') % 2 == 0);
      }
      if(!chk){
         cout << "1\n";
      }else{
         cout << "2\n";
      }
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
