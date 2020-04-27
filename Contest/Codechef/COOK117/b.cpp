#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ld = long double;
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int H,n;
   cin >> H >> n;
   vector<array<int,4>> A(n);
   for(int i=0;i<n;i++){
      cin >> A[i][2] >> A[i][0] >> A[i][1];
      A[i][3] = i;
   }
   sort(all(A));
   vector<int> ans(n);
   f(i,0,n){
      int val = 0;
      int ux = 0, uy = 1;
      int dx = 0, dy = -1; 
      array<int,4> x = A[i];
      f(j,i+1,n){
         array<int,4> y = A[j];
         int vx = y[0]-x[0], vy = y[1]-x[1];
         if(vx == 0){
            ans[y[3]]++;
            ans[x[3]]++;
            continue;
         }
         if (dx * vy - dy * vx > 0 && vx * uy - vy * ux > 0) {
          ++ans[x[3]];
          ++ans[y[3]];
        }
        if(!y[2]){
          if(dx * vy - dy * vx > 0) {
            dx = vx;
            dy = vy;
          }
        }else{
          if (vx * uy - vy * ux > 0) {
            ux = vx;
            uy = vy;
          }
        }
      }
   }
   f(i,0,n){
      cout << ans[i] << " \n"[i==n-1];
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