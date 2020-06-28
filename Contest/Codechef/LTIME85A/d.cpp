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
   vector<int> pos,neg;
   f(i,0,n){
      cin >> a[i];
      if(a[i] > 0){
         pos.pb(a[i]);
      }else{
         neg.pb(a[i]);
      }
   }
   sort(all(a));
   sort(all(pos));
   sort(all(neg));
   if(pos.size() == 0){
      cout << "NO\n";
      return;
   }
   if(neg.empty()){
      for(int i = 0; i+1 < n; i+=2){
         swap(a[i],a[i+1]);
      }
      cout << "YES\n";
      f(i,0,n){
         cout << a[i] << ' ';
      }
      cout << '\n';
      return;
   }
   vector<int> R = {pos[0]};
   for(auto &e : neg){
      R.pb(e);
   }
   f(i,1,pos.size()){
      R.pb(pos[i]);
   }
   for(int i = 2; i+1 < n ; i+= 2){
      swap(R[i],R[i+1]);
   }
   cout << "YES\n";
   for(auto &e : R){
      cout << e << ' ';
   }
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
