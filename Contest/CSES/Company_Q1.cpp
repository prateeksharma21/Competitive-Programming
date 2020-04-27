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
const int MOD = 1e9+7, N = 2e5 + 10; 
const int LG = log2(N)+1;

int n,q;
int parent[N][LG];

void build(){
   f(j,1,LG){
      for(int i=1;i<=n;i++){
         if(parent[i][j-1]){
            parent[i][j] = parent[parent[i][j-1]][j-1];
         }
      }
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> q;
   f(i,2,n+1){
      int e; cin >> e;
      parent[i][0] = e;
   }
   build();
   while(q--){
      int x,k;
      cin >> x >> k;
      int cur = x;
      for(int i=LG;i>=0;i--){
         if((1<<i)<=k){
            k-=(1<<i);
            cur = parent[cur][i];
            if(!cur){
               cur = -1;
               break;
            }
         }
      }
      cout << cur << '\n';
   }
   return 0;
} 