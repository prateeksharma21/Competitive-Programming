#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int cnt[N];
int a[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   int c2 = 0, c4 = 0;

   auto apply = [&](int x){
      if(cnt[x] % 4 == 0){
         c4++;
         c2--;
      }else if(cnt[x] % 2 == 0){
         c2++;
      }
   };

   for(int i = 0; i < n; ++i){
      cin >> a[i];
      ++cnt[a[i]];
      apply(a[i]);
   }

   int q;
   cin >> q;
   while(q--){
      char i;
      int x;
      cin >> i >> x;
      if(i == '+'){
         cnt[x]++;
         apply(x);
      }else{
         cnt[x]--;
         if(cnt[x] % 4 == 1){
            c2--;
         }else if(cnt[x] % 4 == 3){
            c2++;
            c4--;
         }
      }
      if((c4>0 and c2>1) or (c4 > 1)){
         cout << "YES\n";
      }else{
         cout << "NO\n";
      }
   }
   return 0;
}