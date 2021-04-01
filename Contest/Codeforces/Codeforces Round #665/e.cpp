#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
const int N = 1e6;

vector<int> Add[N+1], Remove[N+1]; 
vector<pair<int,int>> Pos(N+1);

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   vector<array<int,3>> A(n),B(m);
   int64_t ans = 1;
   for(auto &i : A){
      cin >> i[0] >> i[1] >> i[2];
      Add[i[1]].push_back(i[0]);
      Remove[i[2]].push_back(i[0]);
      if(i[1] == 0 and i[2] == N){
         ++ans;
      }
   } 
   for(int i = 0; i <= N; ++i){
      Pos[i] = {-1,-1};
   }
   for(auto &i : B){
      cin >> i[0] >> i[1] >> i[2];
      if(i[1] == 0 and i[2] == N){
         ++ans;
      }
      Pos[i[0]] = {i[1],i[2]};
   }
   indexed_set<int> S;
   for(int i = 0; i <= N; ++i){
      for(int v : Add[i]){
         S.insert(v);
      }
      if(Pos[i].first != -1){
         ans += S.order_of_key(Pos[i].second)-S.order_of_key(Pos[i].first);
         ans += S.find(Pos[i].second) != S.end();
      }
      for(int v : Remove[i]){
         S.erase(v);
      }
   }
   cout << ans << '\n';
   return 0;
}