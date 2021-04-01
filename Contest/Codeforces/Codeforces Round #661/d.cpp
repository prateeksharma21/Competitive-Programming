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
      string s;
      cin >> n >> s;
      set<int> se[2];
      int ans = 0;
      vector<int> R(n);
      for(int i = 0; i < n; ++i){
         int v = s[i]-'0';
         if(se[v^1].empty()){
            ans++;
            R[i] = ans;
            se[v].insert(ans);
         }else{
            int k = *se[v^1].begin();
            se[v^1].erase(k);
            R[i] = k;
            se[v].insert(k);
         }
      }
      cout << ans << '\n';
      for(int i = 0; i < n; ++i){
         cout << R[i] << " \n"[ i==n-1 ];
      }
   }
   return 0;
}