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
   vector<int> pos(n);
   vector<int> a(n);
   for(int i = 0; i < n; ++i){
      cin >> a[i];
   }
   int mn = *min_element(all(a));
   vector<int> V;
   for(int i = 0; i < n; ++i){
      if(a[i] % mn == 0){
         V.pb(a[i]);
         pos[i] = 1;
      }
   }
   sort(all(V),greater<int>());
   for(int i = 0; i < n; ++i){
      if(pos[i]){
         a[i] = V.back();
         V.pop_back();
      }
   }
   if(is_sorted(all(a))){
      cout << "YES\n";
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
