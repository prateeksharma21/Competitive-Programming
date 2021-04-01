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
   vector<int> a(n+1);
   f(i,1,n+1){
      cin >> a[i];
   }
   if(is_sorted(all(a))){
      cout << "0\n";
      return;
   }
   if(n == 2){
      cout << "1\n";
      return;
   }
   int l = 1,r = n;
   while(l <= n and a[l] == l) l++;
   while(r > 0 and a[r] == r) r--;
   f(i,l,r+1){
      if(a[i] == i){
         cout << "2\n";
         return;
      }
   }
   cout << "1\n";
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
