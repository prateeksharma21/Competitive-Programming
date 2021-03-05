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
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n, w;
   cin >> n >> w;
   vector<int> A(n);
   for (int &i : A) {
      cin >> i;
   }
   vector<pair<int,int>> wt;
   int sm = 0;
   for (int i = 0; i < n; ++i) {
      int v = A[i];
      if (v >= (w + 1) / 2 and v <= w) {
         cout << "1\n" << i + 1 << '\n';
         return; 
      }
      if (v < (w + 1) / 2) {
         wt.push_back({v, i});
         sm += v;
      }
   }
   if (sm < (w + 1) / 2) {
      cout << "-1\n";
      return;
   }
   int sz = wt.size();
   sm = 0;
   sort(all(wt));
   vector<int> ans;
   for (int i = sz - 1; i >= 0; --i) {
      sm += wt[i].first;
      ans.push_back(wt[i].second);
      if(sm >= (w + 1) / 2) break;
   }
   cout << ans.size() << '\n';
   for (int i : ans) {
      cout << i+1 << ' ';
   }
   cout << '\n';
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
