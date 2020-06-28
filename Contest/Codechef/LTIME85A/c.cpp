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
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e6 + 10;

int cnt[N];

void test(){
   int n,x;
   cin >> n >> x;
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   } 
   int sq = sqrt(x);
   vector<int> A;
   for(int i = 1; i*i <= x ;i++){
      if(x%i == 0){
         if(i <= n)
            A.pb(i);
         if(x/i != i and x/i <= n){
            A.pb(x/i);
         }
      }
   }
   // debug(A);
   sort(all(A));
   int ans = 0;
   for(auto l : A){
      int tt = x/l;
      int cur = 0;
      f(j,0,l){
         cur += a[j];
      }
      if(cur < N){
         cnt[cur]++;
      }
      f(j,l,n){
         cur -= a[j-l];
         cur += a[j];
         if(cur < N){
            cnt[cur]++;
         }
      }
      cur = 0;
      f(j,0,l){
         cur += a[j];
      }
      if(tt-cur > 0){
         ans += cnt[tt-cur];
      }
      f(j,l,n){
         cur -= a[j-l];
         cur += a[j];
         if(tt-cur > 0){
            ans += cnt[tt-cur];
         }
      }
      cur = 0;
      f(j,0,l){
         cur += a[j];
      }
      if(cur < N){
         cnt[cur]--;
      }
      f(j,l,n){
         cur -= a[j-l];
         cur += a[j];
         if(cur < N){
            cnt[cur]--;
         }
      }
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
