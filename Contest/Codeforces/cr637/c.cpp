#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7;
const int N = 1e4 + 5;
const int M = 1e3 + 5; 

int n,m,r,g;
int A[N];
int dist[N][M];
bool vis[N][M];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   f(i,1,m+1){
      cin >> A[i];
   }
   cin >> g >> r;
   A[m+1] = n;
   sort(A,A+m+2);
   deque<pii> q;
   q.pb({0,0});
   vis[0][0] = true;
   int ans = -1;
   while(!q.empty()){
      int v = q.front().F;
      int t = q.front().S;
      q.pop_front();
      if(t == 0){
         int T = n-A[v];
         if(T <= g){
            if(ans == -1){
               ans = (r+g)*dist[v][t]+T;
            }
            ans = min(ans,(r+g)*dist[v][t]+T);
         }
      }
      if(t == g){
         if(!vis[v][0]){
            dist[v][0] = dist[v][t]+1;
            q.pb({v,0});
            vis[v][0] = 1;
         }
         continue;
      }
      if(v!=0){
         int T = t+A[v]-A[v-1];
         if(T <= g and !vis[v-1][T]){
            vis[v-1][T] = true;
            dist[v-1][T] = dist[v][t];
            q.push_front({v-1,T});
         }
      }
      if(v<m-1){
         int T = t+A[v+1]-A[v];
         if(T <= g and !vis[v+1][T]){
            vis[v+1][T] = true;
            dist[v+1][T] = dist[v][t];
            q.push_front({v+1,T});
         }
      }
   }
   cout << ans << '\n';
   return 0;
}