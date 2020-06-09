#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;
 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

string s[51];
int vis[51][51];

void test(){
   int n;
   cin >> n;
   f(i,1,n+1){
      f(j,1,n+1){
         vis[i][j] = 0;
      }
   }
   queue<pair<int, int>> q;
   f(i,1,n+1){
      cin >> s[i];
      s[i] = '.'+s[i];
      f(j,1,n+1){
         if(s[i][j] == '1' and (i==n or j == n)){ 
            q.push({i,j}),vis[i][j] = 1;
         }
      }
   }
   while(!q.empty()){
      auto k = q.front();
      q.pop();
      int x = k.F-1,y = k.S;
      if(x>=1){
         if(!vis[x][y] and s[x][y] == '1'){
            vis[x][y] = 1;
            q.push({x,y});
         }
      }
      x = k.F,y = k.S-1;
      if(y>=1){
         if(!vis[x][y] and s[x][y] == '1'){
            vis[x][y] = 1;
            q.push({x,y});
         }  
      }
   }
   f(i,1,n+1){
      f(j,1,n+1){
         if(s[i][j] == '1' and !vis[i][j]){
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
