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

int n,m;
vector<array<int,3>> E;
int A[N];
int P[N];

int find(int u){
   if(u == P[u]) return u;
   return P[u] = find(P[u]);
}

bool same(int u,int v){
   return find(u) == find(v);
}

void merge(int u,int v){
   u = find(u);
   v = find(v);
   if(rand()%2){
      P[v] = u;
   }else{
      P[u] = v;
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   f(i,1,n+1){
      P[i] = i;
      cin >> A[i];
   }
   int in = min_element(A+1,A+n+1)-A;
   f(i,1,n+1){
      if(i!=in){
         E.pb({A[in]+A[i],i,in});
      }
   }
   f(i,0,m){
      int x,y,w;
      cin >> x >> y >> w;
      E.pb({w,x,y});
   }
   sort(all(E));
   int ans = 0;
   for(auto [w,x,y] : E){
      if(!same(x,y)){
         merge(x,y);
         ans += w;
      }
   }
   cout << ans << '\n';
   return 0;
} 