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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 
const __int128 MX = 1e17;

inline __int128 power(__int128 base, long long ex) {
  __int128 res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res *= base;
    base *= base;
  }
  return res;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> A(n);
   int sm = 0;
   for(int i = 0; i < n; ++i){
      cin >> A[i];
      sm += A[i];
   }
   if(n > 100){
      return cout << sm-n,0;
   }
   sort(A.begin(),A.end());
   int c = 1;
   int ans = LLONG_MAX;
   while(power(c,n) <= 1e17){
      int cur = 0;
      for(int i = 0; i < n; ++i){
         __int128 diff = A[i]-power(c,i);
         if(diff < 0) diff *= -1;
         cur += diff;
      }
      ans = min(ans,cur);
      ++c;
   }
   cout << ans << '\n';
   return 0;
} 