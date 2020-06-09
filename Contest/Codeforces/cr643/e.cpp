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

int n,a,r,m;

vector<int> A;

int cost(int v){
   int l = 0,h = 0;
   for(auto &e : A){
      if(e > v){
         h += e-v;
      }else{
         l += v-e;
      }
   }
   return min(h,l)*min(a+r,m)+(h-min(h,l))*r+(l-min(h,l))*a;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> a >> r >> m;
   A = vector<int>(n);
   f(i,0,n){
      cin >> A[i];
   }
   int l = 0,r = 1e9;
   while(r-l>3){
      int m1 = l+(r-l)/3;
      int m2 = r-(r-l)/3;
      if(cost(m1)>cost(m2)){
         l = m1;
      }else{
         r = m2;
      }
   }
   int ans = 1e18;
   f(i,l,r+1){
      ans = min(ans,cost(i));
   }
   cout << ans << '\n';
   return 0;
}