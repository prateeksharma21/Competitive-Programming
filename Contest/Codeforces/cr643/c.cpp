#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e6 + 10; 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif
int upd[N];
int fin_upd[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int A,B,C,D;
   cin >> A >> B >> C >> D;
   int ans = 0;

   auto update = [&](int x,int y,int v){
      x = max(0ll,x);
      y = min(N-2,y);
      upd[x]+=v;
      upd[y+1]+=(-v);
   };

   f(i,A,B+1){
      int mnz = B-i+1;
      int mxz = B+i-1;
      update(mnz,mnz+C-B,1);
      update(mxz+1,mxz+C-B+1,-1);
   }

   int cur = 0;

   f(i,0,N){
      cur += upd[i];
      fin_upd[i] = cur;
   }

   cur = 0;
   f(i,0,N){
      cur += fin_upd[i];
      if(i>=C and i<=D){
         ans += cur;
      }
   }
   cout << ans << '\n';

   return 0;
}