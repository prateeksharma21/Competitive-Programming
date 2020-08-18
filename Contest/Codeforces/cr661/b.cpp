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
      vector<int> a(n),b(n);
      vector<int> op1(n),op2(n);
      int mn1 = 1e9, mn2 = 1e9;
      for(int i = 0; i < n; ++i){
         cin >> a[i];
         mn1 = min(mn1,a[i]);
      }
      for(int i = 0; i < n; ++i){
         cin >> b[i];
         mn2 = min(mn2,b[i]);
      }
      int ans = 0;
      for(int i = 0; i < n; ++i){
         op1[i] = a[i]-mn1;
         op2[i] = b[i]-mn2;
         int mn = min(op1[i],op2[i]);
         ans += mn;
         op1[i] -= mn;
         op2[i] -= mn;
         ans += op1[i]+op2[i];
      }
      cout << ans << '\n';
   }
   return 0;
}