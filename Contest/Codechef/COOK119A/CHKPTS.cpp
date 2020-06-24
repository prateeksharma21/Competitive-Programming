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
   
   int n,c;
   cin >> n >> c;

   vector<pair<int, int>> A(n);
   for(auto &e : A){
      cin >> e.F >> e.S;
   }

   map<pair<int, int>,vector<pair<int, int>>> G;

   for(auto &e : A){
      int c = -e.S;
      // debug(c);
      G[{e.F+c,0}].pb(e);
   }

   vector<vector<int>> R;
   
   for(auto &e : G){
      sort(all(e.S));
      vector<int> T = {0};
      f(i,1,e.S.size()){
         auto prv = T.back();
         T.pb(prv+e.S[i].F-e.S[i-1].F);
      }
      R.pb(T);
   }

   // debug(R);

   vector<vector<int>> R_n;

   for(auto &e : R){
      map<int,vector<int>> temp;
      for(auto v : e){
         temp[v%c].pb(v);
      }
      for(auto &v : temp){
         R_n.pb(v.S);
      }
   }


   // cout << R_n.size() << ' ';
   int ans = 0;

   // debug(c);
   // debug(R_n);

   for(auto &e : R_n){
      int cost = 0;
      int m = e[(int)e.size()/2];
      for(auto &v : e){
         cost += abs(v-m)/c;
      }
      ans += cost;
   }

   cout << R_n.size() << ' ' << ans << '\n';
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
