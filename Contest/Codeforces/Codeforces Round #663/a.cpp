#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while(tt--){
      int n;
      cin >> n;
      for(int i = 1; i <= n; ++i){
         cout << i << " \n"[i == n];
      }
   }
   return 0;
}