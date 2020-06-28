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

int A[N];

void test(){
   int n;
   cin >> n;
   map<int,int> cnt;
   f(i,0,n){
      cin >> A[i];
      cnt[A[i]]++;
   }
   vector<int> ff,ss;
   for(auto &e : cnt){
      if(e.S > 2){
         cout << "NO\n";
         return;
      }
      if(e.S == 1){
         ff.pb(e.F);
      }else{
         ff.pb(e.F);
         ss.pb(e.F);
      }
   }
   sort(all(ff));
   sort(all(ss));
   reverse(all(ss));
   if(!ff.empty() and !ss.empty() and ff.back() == ss.front()){
      cout << "NO\n";
      return;
   }
   cout << "YES\n";
   for(auto &e : ff) cout << e << ' ';
   for(auto &e : ss) cout << e << ' ';
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
