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

void test(){
   int n,m,a,b;
   cin >> n >> m >> a >> b;
   vector<int> R(n,a);
   vector<int> C(m,b);
   if(n*a != m*b){
      cout << "NO\n";
      return;
   }
   cout << "YES\n";
   vector<vector<int>> ans(n,vector<int>(m));
   int j = 0;
   f(i,0,n){
      int c = 0;
      while(c!=a){
         ans[i][j] = 1;
         j++;
         j %= m;
         c++;
      }
   }
   f(i,0,n){
      f(j,0,m){
         cout << ans[i][j];
      }
      cout << '\n';
   }
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
