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
   if(n <= 30){
      cout << "NO\n";
      return;
   }
   if(n == 36){
      cout << "YES\n" << "5 6 10 15\n";
   }else if(n == 44){
      cout << "YES\n" << "6 7 10 21\n";
   }else if(n == 40){
      cout << "YES\n" << "9 6 10 15\n";
   }else{
      cout << "YES\n6 10 14 " << n-6-10-14 << '\n';
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
