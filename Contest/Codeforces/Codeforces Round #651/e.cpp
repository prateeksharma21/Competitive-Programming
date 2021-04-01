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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e6 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   string s,t;
   cin >> n;
   cin >> s >> t;
   if(count(all(s),'1') != count(all(t),'1')){
      return cout << -1,0;
   }
   vector<int> A(n),B(n);
   vector<int> p10,p01;
   f(i,0,n){
      A[i] = s[i]-'0';
      B[i] = t[i]-'0';
      if(A[i] == 1 and B[i] == 0){
         p10.pb(i);
      }
      if(A[i] == 0 and B[i] == 1){
         p01.pb(i);
      }
   }
   // debug(p10,p01);
   set<pair<int, int>> se;
   f(i,0,p10.size()){
      // int mn = min(p10[i],p01[i]);
      // int mx = max(p10[i],p01[i]);
      se.insert({p10[i],p01[i]});
   }
   int ans = 0;
   debug(se);
   while(!se.empty()){
      auto k = *se.begin();
      se.erase(k);
      while(1){
         pair<int, int> R = {k.S,-1};
         auto kk = se.upper_bound(R);
         if(kk == se.end()) break;
         else{
            k = *kk;
            se.erase(kk);
         }
      }
      ans++;
   }
   cout << ans << '\n';

   return 0;
} 