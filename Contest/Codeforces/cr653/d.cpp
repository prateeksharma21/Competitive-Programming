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


map<int,int> parent;

void test(){
   int n,k;
   cin >> n >> k;
   vector<int> a(n);
   map<int,int> cnt;
   f(i,0,n){
      cin >> a[i];
      if(a[i]%k == 0) continue;
      int v = ((a[i]+k-1)/k)*k;
      cnt[v-a[i]]++;
   }
   if(cnt.empty()){
      cout << "0\n";
      return;
   }
   int cur = k;
   int ans = 0;
   debug(cnt);
   for(auto &e : cnt){
      ans = max(ans,e.F);
      f(i,0,e.S-1){
         ans = max(ans,e.F+cur);
         cur += k;
      }
      cur = k;
   }
   cout << ans+1 << '\n';
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
 