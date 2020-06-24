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
   string s;
   cin >> s;
   vector<int> cnt(26);
   for(auto c : s){
      cnt[c-'a']++;
   }

   int m;
   cin >> m;
   vector<int> b(m);
   f(i,0,m){
      cin >> b[i];
   }

   int n = s.length();

   vector<int> done(m);
   string res(m,'.');

   int up = 25;

   f(i,0,m){
      int mx = 1e9;
      f(j,0,m){
         if(done[j]) continue;
         mx = min(mx,b[j]);
      }
      if(mx == 1e9) break;
      vector<int> pos;
      f(j,0,m){
         if(done[j]) continue;
         if(mx == b[j]){
            pos.pb(j);
         }
      }
      // debug(pos,mx);
      int v ;
      for(int j = up; j >= 0; --j){
         if(cnt[j] >= pos.size()){
            v = j;
            break;
         }
      }
      // debug(v);
      up = v-1;
      for(auto &e : pos){
         res[e] = char(v+'a');
      }
      for(auto &e : pos){
         f(j,0,m){
            if(!done[j]){
               b[j] -= abs(j-e);
            }
         }
      }

      for(auto &e : pos) done[e] = 1;
   }

   cout << res << '\n';

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
