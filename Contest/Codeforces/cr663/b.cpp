#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--){
      int n,m;
      cin >> n >> m;
      string s[n];
      for(int i = 0; i < n; ++i){
         cin >> s[i];
      }
      int v = 0;
      for(int i = 0; i < m-1; ++i){
         if(s[n-1][i] == 'D') v++;
      }
      for(int i = 0; i < n-1; ++i){
         if(s[i][m-1] == 'R') v++;
      }
      cout << v << '\n';
   }
   return 0;
}