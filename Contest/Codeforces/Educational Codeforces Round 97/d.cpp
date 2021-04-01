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
   for(int &i : A) {
      cin >> i;
   }
   if(n == 2) {
      cout << "1\n";
      return;
   }
   vector<int> cnt;
   int cur = 1;
   for(int i = 2; i < n; ++i) {
      if(A[i] > A[i-1]) {
         cur++;
      } else {
         cnt.push_back(cur);
         cur = 1;
      }
   }
   cnt.push_back(cur);
   int prv = 1;
   int ans = 0;
   debug(cnt);
   for(int i = 0; i < cnt.size(); ) {
      int c = 0;
      int now = 0;
      while(c < prv and i < n) {
         ++c;
         now += cnt[i];
         ++i;
      }
      prv = now;
      ++ans;
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