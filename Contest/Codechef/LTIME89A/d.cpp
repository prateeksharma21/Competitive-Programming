#ifdef Prateek
  #include "\Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e4 + 1;

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
   int l, r;
   cin >> l >> r;
   int ans = 0;
   int ff = 0, ss = 0;
   if(l == 1) {
      cout << r*(r+1)/2 << '\n';
      return;
   }
   vector<vector<int>> rng;
   for(int i = l; i <= r; ++i) {
      ff += i;
      ss += (r-(i-l));
      assert(ss >= ff);
      rng.push_back({ff,ss});
   }
   vector<vector<int>> res = merge(rng);
   for(auto i : res) {
      ans += (i[1]-i[0]+1);
   }
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();
   return 0;
}