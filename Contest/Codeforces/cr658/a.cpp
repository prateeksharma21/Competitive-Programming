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
   int n,m;
   cin >> n >> m;
   vector<int> a(n),b(m);
   map<int,int> done;
   f(i,0,n) cin >> a[i],done[a[i]] = 1;
   int ans = -1;
   f(i,0,m){
      cin >> b[i];
      if(done[b[i]]){
         ans = b[i];
      }
   }
   if(ans != -1){
      cout << "YES\n1 " << ans << '\n';
   }else{
      cout << "NO\n";
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
