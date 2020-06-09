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
   int a,b;
   cin >> a >> b;
   if(a > b) swap(a,b);
   if(b%a != 0){
      cout << "-1\n";
      return;
   }
   b /= a;
   int ans = 0;
   while(b%8 == 0) b /= 8,ans++;
   while(b%4 == 0) b /= 4,ans++;
   while(b%2 == 0) b /= 2,ans++;
   if(b == 1){
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
