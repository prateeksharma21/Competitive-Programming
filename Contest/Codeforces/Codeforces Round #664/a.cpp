#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--){
      int r,g,b,w;
      cin >> r >> g >> b >> w;
      int chk = 0;
      for(int i = 0; i < 10; ++i){
         int c = (r%2)+(g%2)+(b%2)+(w%2);
         if(c <= 1){
            chk = 1;
            break;
         }
         if(r and g and b){
            --r,--g,--b;
            w += 3;
         }
      }
      if(chk){
         cout << "Yes\n";
      }else{
         cout << "No\n";
      }
   }
   return 0;
}