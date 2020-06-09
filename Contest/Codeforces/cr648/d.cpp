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

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void test(){
   int n,m;
   cin >> n >> m;
   vector<vector<int>> vis(n,vector<int>(m));
   vector<string> s(n);
   int bad = 0,good = 0;
   vector<pair<int, int>> A;
   f(i,0,n){
      cin >> s[i];
      f(j,0,m){
         if(s[i][j] == 'B'){
            bad++;
            A.pb({i,j});
         }
         if(s[i][j] == 'G'){
            good++;
         }
      }
   }
   if(s[n-1][m-1] == 'B'){
      cout << "NO\n";
      return;
   }

   auto chk = [&](int x,int y){
      return x>=0 and x<n and y>=0 and y<m and s[x][y] != '#';
   };

   queue<pair<int, int>> q;
   q.push({n-1,m-1});
   vis[n-1][m-1] = 1;
   while(!q.empty()){
      auto k = q.front();
      q.pop();
      f(i,0,4){
         int x = k.F+dx[i];
         int y = k.S+dy[i];
         if(chk(x,y) and !vis[x][y]){
            vis[x][y] = 1;
            q.push({x,y});
         }
      }
   }
   // debug(1);
   f(i,0,n){
      f(j,0,m){
         if(s[i][j] == 'B' and vis[i][j]){
            f(k,0,4){
               int x = i+dx[k];
               int y = j+dy[k];
               if(chk(x,y)){
                  if(vis[x][y]){
                     if(s[x][y] == 'G'){
                        // debug(x,y);
                        cout << "NO\n";
                        return;
                     }
                     if(s[x][y] == 'B'){
                        continue;
                     }
                     s[x][y] = '#';
                  }
               }
            }
         }
      }
   }
   vis = vector<vector<int>>(n,vector<int>(m));
   if(s[n-1][m-1] != '#'){
      q.push({n-1,m-1});
      vis[n-1][m-1] = 1;
   }
   while(!q.empty()){
      auto k = q.front();
      q.pop();
      f(i,0,4){
         int x = k.F+dx[i];
         int y = k.S+dy[i];
         if(chk(x,y) and !vis[x][y]){
            vis[x][y] = 1;
            q.push({x,y});
         }
      }
   }
   // debug(vis);
   // debug(s);
   f(i,0,n){
      f(j,0,m){
         if(s[i][j] == 'B' and vis[i][j]){
            cout << "NO\n";
            return;
         }
         if(s[i][j] == 'G' and !vis[i][j]){
            cout << "NO\n";
            return;
         }
      }
   }
   cout << "YES\n";
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
