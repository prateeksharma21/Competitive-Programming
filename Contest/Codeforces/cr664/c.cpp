#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   vector<int> a(n),b(m);
   for(int i = 0; i < n; ++i){
      cin >> a[i];
   }
   for(int i = 0; i < m; ++i){
      cin >> b[i];
   }
   for(int mask = 0; mask <= (1<<9); ++mask){
      int f = 1;
      for(int i = 0; i < n; ++i){
         int c = 0;
         for(int j = 0; j < m; ++j){
            if((mask|(a[i]&b[j])) == mask){
               c = 1;
            }
         }
         if(!c){
            f = 0;
         }
      }
      if(f){
         cout << mask;
         return 0;
      }
   }
   return 0;
}