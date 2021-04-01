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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int a[7];
   for(int i = 1; i <= 6; ++i) {
      cin >> a[i];
   }
   int n;
   cin >> n;
   vector<int> b(n);
   vector<pair<int,int>> A;
   for(int i = 0; i < n; ++i) {
      cin >> b[i];
      for(int j = 1; j <= 6; ++j) {
         A.push_back({b[i]-a[j], i});
      }
   }
   sort(A.begin(), A.end());
   debug(A);
   vector<int> cnt(n);
   set<int> done; 
   int ans = 1e18;
   for(int l = 0, r = 0; l < A.size(); ++l) {
      while(r < A.size() and done.size() != n) {
         done.insert(A[r].second);
         cnt[A[r].second]++;
         ++r;
      }
      if(done.size() != n) break;
      ans = min(ans, A[r-1].first-A[l].first);
      --cnt[A[l].second];
      if(!cnt[A[l].second]) {
         done.erase(A[l].second);
      }
   }
   cout << ans << '\n';
   return 0;
}