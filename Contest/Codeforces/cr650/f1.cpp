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

   map<int,vector<int>> Pos;

   f(i,1,n+1){
      cin >> a[i];
      Pos[a[i]].pb(i);
   }

   vector<int> b = a;
   sort(all(b));

   vector<int> inc(n+2),dcr(n+2);
   vector<int> dp(n+1);

   f(i,1,n+1){
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
