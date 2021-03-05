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
   vector<int> A(n);
   vector<int> cnt(61);
   for(int &i : A) {
      cin >> i;
      for(int j = 0; j < 30; ++j) {
         if((i >> j) & 1) {
            cnt[j]++;
         }
      }
   }
   int ans = 0;
   for(int i = 0; i < 60; ++i) {
      int need = 1;
      ans += bool(cnt[i])*(1LL << i);
      cnt[i+1] += cnt[i]/2;
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