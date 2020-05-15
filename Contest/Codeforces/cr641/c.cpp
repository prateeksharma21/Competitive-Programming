#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m,t;
   cin >> n >> m >> t;
   vector<vector<bool>> vis(n,vector<bool>(m));
   vector<vector<int>> D(n,vector<int>(m));
   vector<vector<int>> A(n,vector<int>(m));
   f(i,0,n){
      f(j,0,m){
         char c; cin >> c;
         A[i][j] = c-'0';
      }
   }
   queue<pii> q;
   f(i,0,n){
      f(j,0,m){
         int c = 0,v = A[i][j];
         if(i>0 and A[i-1][j]==v){
            c = 1;
         }
         if(i<n-1 and A[i+1][j] == v){
            c = 1;
         }
         if(j>0 and A[i][j-1]==v){
            c = 1;
         }
         if(j<m-1 and A[i][j+1] == v){
            c = 1;
         }
         if(c){
            q.push({i,j});
            vis[i][j] = 1;
            D[i][j] = 1;
         }
      }
   }
   while(!q.empty()){
      auto k = q.front();
      q.pop();
      f(i,0,4){
         int x = k.F+dx[i],y = k.S+dy[i];
         if(x>=0 and x<n and y>=0 and y<m and !vis[x][y]){
            vis[x][y] = 1;
            D[x][y] = D[k.F][k.S]+1;
            q.push({x,y});
         }
      }
   }
   while(t--){
      int i,j;
      ll p;
      cin >> i >> j >> p;
      i--;
      j--;
      if(D[i][j]){
         if(p<D[i][j]){
            cout << A[i][j] << '\n';
         }else{
            if((p-D[i][j])&1){
               cout << A[i][j] << '\n';
            }else{
               cout << (A[i][j]^1) << '\n';
            }
         }
      }else{
         cout << A[i][j] << '\n';
      }
   }
   return 0;
}