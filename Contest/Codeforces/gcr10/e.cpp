#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
         cout << ((i&1)*(1LL<<(i+j))) << ' ';
      }
      cout << endl;
   }
   int q;
   cin >> q;
   while(q--){
      int sm;
      cin >> sm;
      int x = 0, y = 0;
      cout << x+1 << ' ' << y+1 << endl;
      for(int i = 0; i < 2*n-2 ; ++i){
         if(x % 2 == 0){
            if(((1LL<<(x+1+y))|sm) == sm){
               x++;
            }else{
               y++;
            }
         }else{
            if(((1LL<<(x+1+y))|sm) == sm){
               y++;
            }else{
               x++;
            }
         }
         cout << x+1 << ' ' << y+1 << endl;
      }
   }
   return 0;
}