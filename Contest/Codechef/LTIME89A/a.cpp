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
   int n, q;
   cin >> n >> q;
   vector<int> A(n+2);
   for(int i = 1; i <= n; ++i) {
      cin >> A[i];
   }
   int ans = 0;
   for(int i = 1, j = 1; i <= n; i = j) {
      while(j <= n and A[i] == A[j]) ++j;
      ++ans;
   }
   while(q--) {
      int x, y;
      cin >> x >> y;
      if (A[x] == A[x-1] and A[x] == A[x+1]) {
         ans += 2;
      } else if(A[x] == A[x-1] or A[x] == A[x+1]) {
         ans ++;
      }
      A[x] = y;
      if (A[x] == A[x-1] and A[x] == A[x+1]) {
         ans -= 2;
      } else if(A[x] == A[x-1] or A[x] == A[x+1]) {
         ans --;
      }
      cout << ans << '\n';
   }
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