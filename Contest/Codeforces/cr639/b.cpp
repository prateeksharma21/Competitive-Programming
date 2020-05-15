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

int n,m;
vector<string> s;
int vis[1010][1010];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int M[1010][1010];

bool chk(){
   f(i,1,n+1){
      vector<int> A;
      int prv = 0;
      f(j,1,m+1){
         if(s[i][j] == '#'){
            if(prv){
               if(j-prv!=1){
                  return false;
               }
            }
            prv = j;
         }
      }
   }
   f(i,1,m+1){
      vector<int> A;
      int prv = 0;
      f(j,1,n+1){
         if(s[j][i] == '#'){
            if(prv){
               if(j-prv!=1){
                  return false;
               }
            }
            prv = j;
         }
      }
   }
   return true;
}

void dfs(int x,int y){
   if(x<=0 or y<=0 or x>n or y>m) return;
   if(vis[x][y]) return;
   if(s[x][y] != '#') return;
   M[x][y] = 1;
   vis[x][y] = 1;
   f(i,0,4){
      dfs(x+dx[i],y+dy[i]);
   }
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   s = vector<string>(n+1);
   f(i,1,n+1){
      cin >> s[i];
      s[i] = '?'+s[i];
   }
   if(!chk()){
      cout << "-1\n";
      return 0;
   }
   int ans = 0;
   f(i,1,n+1){
      f(j,1,m+1){
         if(!vis[i][j] and s[i][j] == '#'){
            dfs(i,j);
            ans++;
         }
      }
   }
   vector<int> R,C;
   f(i,1,n+1){
      int c = 0;
      f(j,1,m+1){
         if(M[i][j]){
            c = 1;
         }
      }
      if(!c){
         R.pb(i);
      }
   }
   f(i,1,m+1){
      int c = 0;
      f(j,1,n+1){
         if(M[j][i]){
            c = 1;
         }
      }
      if(!c){
         C.pb(i);
      }
   }
   if(R.empty() and C.empty()){
      cout << ans << '\n';
      return 0;
   }
   if(R.empty() or C.empty()){
      cout << "-1\n";
      return 0;
   }
   cout << ans << '\n';
   return 0;
}