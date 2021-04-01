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
      int ans = 0;
      for(int s = 2; s <= 2*n; ++s){
         vector<int> cnt(2*n);
         int v = 0;
         for(int i = 0; i < n; ++i){
            if(s-a[i] > 0){
               if(cnt[s-a[i]]){
                  v++;
                  --cnt[s-a[i]];
               }else{
                  cnt[a[i]]++;
               }
            }
         }
         ans = max(ans,v);
      }
      cout << ans << '\n';
   }
   return 0;
}