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
   int n,m,x,y;
   cin >> n >> m >> x >> y;
   string s[n];
   int c = 0;
   f(i,0,n){
      cin >> s[i];
      f(j,0,m){
         if(s[i][j] == '.'){
            c++;
         }
      }
   }
   if(2*x<=y){
      cout << c*x << '\n';
      return;
   }
   int ans = 0;
   f(i,0,n){
      f(j,0,m){
         if(s[i][j] == '.'){
            if(j<m-1){
               if(s[i][j+1] == '.'){
                  s[i][j] = s[i][j+1] = '*';
                  ans += y;
               }else{
                  s[i][j] = '.';
                  ans += x;
               }
            }else{
               ans += x;
               s[i][j] = '.';
            }
         }
      }
   }
   cout << ans << '\n';
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
