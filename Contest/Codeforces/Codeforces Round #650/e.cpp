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
   int n,k;
   cin >> n >> k;
   string s;
   cin >> s;

   vector<int> cnt(26);

   for(auto &e : s){
      cnt[e-'a']++;
   }

   sort(all(cnt));

   for(int len = n; len >= 1; len--){
      vector<int> G[len];
      f(i,0,len){
         G[i].pb((i+k)%len);
      }
      
      vector<int> vis(len);
      int c = 0;

      function<void(int)> dfs = [&](int u){
         vis[u] = 1;
         c++;
         for(auto &v : G[u]){
            if(!vis[v]){
               dfs(v);
            }
         }
      };

      int chk = 1;
      vector<int> C = cnt;

      f(i,0,len){
         if(!vis[i]){
            c = 0;
            dfs(i);
            int flag = 0;
            f(j,0,26){
               if(C[j]>=c){
                  C[j] -= c;
                  flag = 1;
                  break;
               }
            }
            if(!flag){
               chk = 0;
               break;
            }
         }
      }

      if(chk){
         cout << len << '\n';
         return;
      }

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
