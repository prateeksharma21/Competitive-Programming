#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m,u,q;
   cin >> n >> m >> u >> q;
   vector<vector<int>> A(n+5,vector<int>(m+5));
   f(i,1,n+1){
      f(j,1,m+1){
         cin >> A[i][j];
      }
   }
   vector<vector<int>> upd(n+5,vector<int>(m+5));
   while(u--){
      int k,r1,c1,r2,c2;
      cin >> k >> r1 >> c1 >> r2 >> c2;
      r1++;
      c1++;
      r2++;
      c2++;
      upd[r1][c1] += k;
      upd[r2+1][c1] -= k;
      upd[r1][c2+1] -= k;
      upd[r2+1][c2+1] += k;
   }
   f(i,1,n+1){
      f(j,1,m+1){
         upd[i][j] += upd[i-1][j];
      }
   }
   f(i,1,n+1){
      f(j,1,m+1){
         upd[i][j] += upd[i][j-1];
         A[i][j] += upd[i][j];
      }
   }
   vector<vector<int>> pre(n+5,vector<int>(m+5));
   f(i,1,n+1){
      f(j,1,m+1){
         pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+A[i][j];
      }
   }
   while(q--){
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1++;
      x2++;
      y1++;
      y2++;
      cout << pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1] << '\n';
   }
   return 0;
}