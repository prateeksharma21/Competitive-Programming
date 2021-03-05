#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
// #define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

int ans;
int n;
int a[21];

void dfs(int sm, int mn, deque<int> a) {
   if (a.empty()) {
      ans = max(ans, mn);
      return;
   }
   int fr = a.front();
   a.pop_front();
   sm += fr;
   mn = min(sm, mn);
   dfs(sm, mn, a);
   if (!a.empty()) {
      int bk = a.back();
      a.pop_back();
      a.push_front(bk);
      dfs(sm, mn, a);
   }
}

void test(){
   cin >> n;
   ans = -MOD;
   vector <int> a(n), v;
   deque <int> dq;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      dq.push_back(a[i]);
   }
   dfs(0, MOD, dq);
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