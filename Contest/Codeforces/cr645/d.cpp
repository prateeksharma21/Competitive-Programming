#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 


#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,x;
   cin >> n >> x;
   vector<int> A(2*n);
   f(i,0,n){
      cin >> A[i];
      A[i+n] = A[i];
   }
   vector<int> Pre(2*n),val(2*n);
   Pre[0] = A[0];
   val[0] = A[0]*(A[0]+1)/2;
   f(i,1,2*n){
      Pre[i] = Pre[i-1]+A[i];
      val[i] = val[i-1]+(A[i]*(A[i]+1))/2;
   }

   // debug(Pre,val);

   auto V = [&](int in,int v){
      int done = x-(A[in]-v+1);
      if(done<=0){
         return (v+x-1)*(v+x)/2-v*(v-1)/2;
      }
      int R = A[in]*(A[in]+1)/2-v*(v-1)/2;
      auto k = lower_bound(all(Pre),Pre[in]+done)-Pre.begin();
      k--;
      R += val[k]-val[in];
      done -= (Pre[k]-Pre[in]);
      R += done*(done+1)/2;
      return R;
   };

   int ans = 0;

   f(i,0,n){
      int l = 1,r = A[i];
      while(r-l>3){
         int m1 = l+(r-l)/3;
         int m2 = r-(r-l)/3;
         int c1 = V(i,m1),c2 = V(i,m2);
         if(c1<c2) l =m1;
         else r = m2;
      }
      f(j,l,r+1){
         ans = max(ans,V(i,j));
         // debug(V(i,j));
      }
      // debug(ans,l,r);
   }
   cout << ans << '\n';
   return 0;
}