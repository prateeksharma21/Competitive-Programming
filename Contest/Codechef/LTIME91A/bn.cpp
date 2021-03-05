#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      string s, p;
      cin >> n >> s >> p;
      int c = 0;
      int flg = 1;
      for (int i = 0; i < n; ++i) {
         if (s[i] != p[i]) {
            if (s[i] == '1') ++c;
            else --c;
         }
         if (c < 0) {
            flg = 0;
            break;
         }
      }
      if (flg and c == 0) {
         cout << "Yes\n";
      } else {
         cout << "No\n";
      }
   }
   return 0;
}