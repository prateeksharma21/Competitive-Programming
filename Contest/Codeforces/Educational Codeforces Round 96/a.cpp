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
const int MOD = 1e9+7, N = 1e3 + 10;

pair<int,int> sm[N];

void test(){
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      int req = n-3*i;
      if(req < 0) break;
      if(sm[req].first != -1) {
         cout << i << ' ' << sm[req].first << ' ' << sm[req].second << '\n';
         return;
      }
   }
   cout << "-1\n";
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   for(int i = 0; i < N; ++i) {
      sm[i] = {-1,-1};
   }

   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
         int sum = i*5+j*7;
         if(sum < N) {
            sm[sum] = {i,j};
         }
      }
   }

   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
