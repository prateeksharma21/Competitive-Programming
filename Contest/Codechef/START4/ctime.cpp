#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
   vector<vector<int>> R;
   if(intervals.empty()){
      return R;
   }
   sort(intervals.begin(),intervals.end());
   vector<int> LR = intervals.front();
   int sz = intervals.size();
   for(int i = 1; i < sz; ++i) {
      if(LR[1] >= intervals[i][0]){
          LR[1] = max(intervals[i][1],LR[1]);
      }else{
          R.push_back(LR);
          LR = intervals[i];
      }
   }
   R.push_back(LR);
   return R;
}

void test(){
   int n, k, f;
   cin >> n >> k >> f;
   vector<vector<int>> intervals;
   for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      intervals.push_back({l, r});
   }
   intervals = merge(intervals);
   int total = f;
   for (auto v : intervals) {
      total -= (v[1] - v[0]);
   }
   cout << (total >= k ? "YES" : "NO") << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}