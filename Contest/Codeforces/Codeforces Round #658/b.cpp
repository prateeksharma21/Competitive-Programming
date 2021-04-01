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
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   int c = 0;
   f(i,0,n){
      c += (a[i] == 1);
   }
   debug(c);
   if(c == n){
      cout << ((c & 1)?"First":"Second") << '\n';
      return;
   }
   int i = 0;
   while(a[i] == 1 and i < n){
      i++;
   }
   c = i;
   cout << ((c % 2 == 0)?"First":"Second") << '\n';
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
