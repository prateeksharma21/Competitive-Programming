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
   if(n == 1){
      cout << "0\n";
      return;
   }
   int c2 = 0;
   while(n%2 == 0) c2++,n/=2;
   int c3 = 0;
   while(n%3 == 0) c3++,n /= 3;
   if(n != 1){
      cout << "-1\n";
      return;
   }
   if(c2 > c3){
      cout << "-1\n";
      return;
   }
   cout << (c3-c2)+c3 << '\n';
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
