#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m,sx,sy;
   cin >> n >> m >> sx >> sy;
   vector<pair<int, int>> ans;
   ans.push_back({sx,sy});
   for(int i = 1; i <= m; ++i){
      if(i != sy){
         ans.push_back({sx,i});
      }
   }
   int x = sx-1;
   int lst = m;
   while(x >= 1){
      if(lst == m){
         int c = lst;
         while(c >= 1){
            ans.push_back({x,c});
            --c;
         }
         lst = 1;
      }else{
         int c = 1;
         while(c <= m){
            ans.push_back({x,c});
            ++c;
         }
         lst = m;
      }
      --x;
   }

   x = sx+1;
   while(x <= n){
      if(lst == m){
         int c = lst;
         while(c >= 1){
            ans.push_back({x,c});
            --c;
         }
         lst = 1;
      }else{
         int c = 1;
         while(c <= m){
            ans.push_back({x,c});
            ++c;
         }
         lst = m;
      }
      ++x;
   }
   for(auto i : ans){
      cout << i.first << ' ' << i.second << '\n';
   }
   return 0;
}