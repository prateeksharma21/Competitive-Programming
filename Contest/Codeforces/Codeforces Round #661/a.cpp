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
      vector<int> a(n);
      for(int i = 0; i < n; ++i){
         cin >> a[i];
      }
      sort(a.begin(),a.end());
      int chk = 1;
      for(int i = 1; i < n; ++i){
         chk &= (a[i]-a[i-1] <= 1);
      }
      if(chk){
         cout << "YES\n";
      }else{
         cout << "NO\n";
      }
   }
   return 0;
}