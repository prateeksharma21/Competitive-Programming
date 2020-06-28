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
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n,k;
   cin >> n >> k;
   vector<int> a(n);
   vector<int> cnt(32);
   f(i,0,n){
      cin >> a[i];
      f(j,0,32){
         if(a[i] & (1ll<<j)){
            cnt[j]++;
         }
      }
   }
   vector<pair<int, int>> A;
   f(i,0,32){
      A.pb({-((1ll<<i)*cnt[i]),i});
   }
   sort(all(A));
   int x = 0;
   f(i,0,k){
      x |= (1ll<<A[i].S);
   }
   cout << x << '\n';
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
