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
const int MOD = 1e9+7, N = 5e5 + 10;
const int M = sqrt(N);

void test(){
   int n,a,b;
   cin >> n >> a >> b;
   
   vector<int> parent(n+1);
   vector<int> tin(n+1);
   vector<int> tout(n+1);
   vector<vector<int>> G(n+1);

   int timer = 0;

   f(i,2,n+1){
      cin >> parent[i];
      G[parent[i]].pb(i);
      G[i].pb(parent[i]);
   }

   int ans = 0;
   vector<int> dist(n+1),d1(n+1),d2(n+1);
   dist[0] = -1;

   map<int,int> mp;

   function<void(int,int)> dfs = [&](int u,int p){
      tin[u] = timer++;
      dist[u] = dist[p]+1;
      d1[u] = dist[u]%a;
      d2[u] = dist[u]%b;
      for(auto &v : G[u]){
         if(v != parent[u]){
            dfs(v,u);
         }
      }
      tout[u] = timer++;
   };

   dfs(1,0);

   int cnt1 = 0,cnt2 = 0;

   f(i,1,n+1){
      mp[dist[i]]++;
      cnt1 += 1+dist[i]/a;
      cnt2 += 1+dist[i]/b;
   }

   vector<int> R1(timer),R2(timer);
   f(i,1,n+1){
      R1[tin[i]] = R1[tout[i]] = d1[i];
      R2[tin[i]] = R2[tout[i]] = d2[i];
   }

   vector<int> G1[a],G2[b];
   f(i,0,timer){
      G1[R1[i]].pb(i);
      G2[R2[i]].pb(i);
   }

   int cnt = cnt1*n+cnt2*n;

   f(i,1,n+1){
      int l = tin[i], r = tout[i];
      int frq1 = upper_bound(all(G1[R1[l]]),r)-lower_bound(all(G1[R1[l]]),l);
      int frq2 = upper_bound(all(G2[R2[l]]),r)-lower_bound(all(G2[R2[l]]),l);
      frq1 /= 2;
      frq2 /= 2;
      cnt -= frq1*frq2;
   }

   long double answ = cnt;
   answ /= (n*n);
   cout << setprecision(10) << fixed << answ << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt){
      cout << "Case #" << i+1 << ": ";
      test();   
   }
   return 0;
}