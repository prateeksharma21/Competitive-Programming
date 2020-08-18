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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,h,m,k;
   cin >> n >> h >> m >> k;
   vector<pair<int, int>> A(n);
   for(auto &e : A){
      cin >> e.F >> e.S;
   }
   vector<int> B;
   vector<pair<int, int>> R;
   f(i,0,n){
      B.pb(A[i].S);
      R.pb({A[i].S,i+1});
   }
   sort(all(B));
   sort(all(R));
   int rem = m/2-k;
   int ans = 0;
   f(i,0,n){
      int cur = B[i];
      int v = 0;
      if(cur+rem >= m){
         v += n-i;
         v += upper_bound(all(B),(cur+rem)%m)-B.begin();
      }else{
         v += upper_bound(all(B),(cur+rem))-B.begin()-i;
      }
      cur = B[i]+m/2;
      cur %= m;
      if(cur+rem >= m){
         auto pt = lower_bound(all(B),cur)-B.begin();
         v += n-pt;
         v += upper_bound(all(B),(cur+rem)%m)-B.begin();
      }else{
         v += upper_bound(all(B),(cur+rem))-lower_bound(all(B),cur);
      }
      ans = max(ans,v);
   }
   f(i,0,n){
      int cur = B[i];
      int v = 0;
      int done1 = 0;
      if(cur+rem >= m){
         v += n-i;
         v += upper_bound(all(B),(cur+rem)%m)-B.begin();
      }else{
         v += upper_bound(all(B),(cur+rem))-B.begin()-i;
      }
      done1 = v;
      cur = B[i]+m/2;
      cur %= m;
      if(cur+rem >= m){
         auto pt = lower_bound(all(B),cur)-B.begin();
         v += n-pt;
         v += upper_bound(all(B),(cur+rem)%m)-B.begin();
      }else{
         v += upper_bound(all(B),(cur+rem))-lower_bound(all(B),cur);
      }
      int done2 = v-done1;
      if(v == ans){
         if(B[i] >= m/2) B[i] -= m/2;
         cout << n-ans << ' ' << B[i] << '\n';
         vector<int> chk(n+1);
         int ff = i;
         while(done1--){
            chk[R[ff].S] = 1;
            ff++;
            ff %= n;
         }       
         auto pt = lower_bound(all(B),cur)-B.begin();
         while(done2--){
            chk[R[pt].S] = 1;
            pt++;
            pt %= n;
         }
         f(i,1,n+1){
            if(!chk[i]){
               cout << i << ' ';
            }
         }
         cout << '\n';
         return 0;
      }
   }
   return 0;
} 