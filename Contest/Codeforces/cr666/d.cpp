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
   multiset<int> s;
   vector<int> a(n);
   for(int i = 0; i < n; ++i){
      cin >> a[i];
      s.insert(a[i]);
   }
   int c = 1;
   int prv = *(prev(s.end()));
   --prv;
   debug(prv);
   s.erase(prev(s.end()));
   while(!s.empty()){
      int cur = *(prev(s.end()));
      --cur;
      s.erase(prev(s.end()));
      if(prv){
         s.insert(prv);
      }
      prv = cur;
      c ^= 1;
   }
   if(c){
      cout << "T\n";
   }else{
      cout << "HL\n";
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
