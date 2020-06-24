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

void print(int x){
   if(x == 1){
      cout << "Ashishgup\n";
   }else{
      cout << "FastestFinger\n";
   }
}

void test(){
   int n;
   cin >> n;
   if(n == 1){
      print(2);
      return;
   }
   if(n == 2 or n%2 == 1){
      print(1);
      return;
   }
   int nn = n,c = 0;
   while(n%2 == 0) n /= 2,c++;
   if(c != 1){
      if(n == 1){
         cout << "FastestFinger\n";
      }else{
         cout << "Ashishgup\n";
      }
      return;
   }
   for(int i = 3; i*i <= n; i++){
      while(n % i == 0){
         n /= i;
         c++;
      }
   }
   if(n > 1) c++;
   if(c != 2){
      cout << "Ashishgup\n";   
   }else{
      cout << "FastestFinger\n";
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
