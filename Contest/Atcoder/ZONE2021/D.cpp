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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin >> s;
   int c = 0;
   deque<int> q;
   for (char i : s) {
      if (i == 'R') {
         c ^= 1;
         continue;
      }
      if (c) {
         q.push_front(i);
      } else {
         q.push_back(i);
      }
   }
   string ans = "";
   for (int i = 0; i < q.size(); ++i) {
      ans += q[i];
   }
   if (c) reverse(all(ans));
   vector<char> stk;
   int n = ans.size();
   for (int i = 0; i < n; ++i) {
      if (stk.empty() or stk.back() != ans[i]) {
         stk.push_back(ans[i]);
      } else {
         stk.pop_back();
      }
   }
   for (char i : stk) cout << i;
   return 0;
}