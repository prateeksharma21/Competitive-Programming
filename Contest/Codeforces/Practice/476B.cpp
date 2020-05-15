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

string a,b;
int n;
vector<int> P;

void dfs(int u,int v){
   if(u == n){
      P.pb(v);
      return;
   }
   if(b[u] == '-'){
      dfs(u+1,v-1);
   }else if(b[u] == '+'){
      dfs(u+1,v+1);
   }else{
      dfs(u+1,v+1);
      dfs(u+1,v-1);
   }
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> a >> b;
   n = a.length();
   dfs(0,0);
   int p = 0;
   f(i,0,n){
      if(a[i] == '-') p--;
      else p++;
   }
   int ans = 0;
   for(auto &e : P) ans += (e == p);
   double R = ans;
   R /= P.size();
   cout << setprecision(14) << fixed << R << '\n';
   return 0;
} 