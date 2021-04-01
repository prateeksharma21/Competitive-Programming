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
   string a,b;
   cin >> a >> b;
   vector<int> R1,R2;
   f(i,1,n){
      if(a[i] != a[i-1]){
         R1.pb(i);
      }
   }
   if(a[n-1] == '1') R1.pb(n);
   f(i,1,n){
      if(b[i] != b[i-1]){
         R2.pb(i);
      }
   }
   if(b[n-1] == '1') R2.pb(n);
   reverse(all(R2));
   cout << R1.size() + R2.size() << ' ';
   for(auto &e : R1) cout << e << ' ';
   for(auto &e : R2) cout << e << ' ';
   cout << '\n';
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
