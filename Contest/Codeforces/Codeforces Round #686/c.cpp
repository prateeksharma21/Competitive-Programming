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
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector <int> A(n + 1) , pos[n+1];
   for (int i = 1; i <= n; ++i) {
      cin >> A[i];
      pos[A[i]].push_back(i);
   }
   int rem = 1e9;
   for (int i = 1; i <= n; ++i) {
      if (pos[i].empty()) continue;
      int ans = pos[i].size() + 1;
      // cout << "pos "<< pos[i].size() << '\n';
      if (pos[i].front() == 1) --ans;
      for (int j = 1; j < pos[i].size(); ++j) {
         if (pos[i][j-1] + 1 == pos[i][j]) --ans;
      }
      if (pos[i].back() == n) --ans;
      rem = min(rem, ans);
   }
   cout << rem << '\n';
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