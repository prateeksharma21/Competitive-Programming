#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n,l,r;
   cin >> n >> l >> r;
   int cur = 0,pos = n;
   f(i,1,n+1){
      int v = 2*(n-i);
      cur += v;
      // cout << cur << '\n';
      if(cur>=l){
         pos = i;
         // cout << i << '\n';
         cur -= v;
         break;
      }
   }
   // cout << "pos "<< cur << ' '<< pos << '\n';
   f(j,pos,n+1){
      int v = j+1;
      f(i,1,2*(n-j)+1){
         cur++;
         if(cur >= l and cur <= r){
            if(i&1){
               cout << j << ' ';
            }else{
               cout << v++ << ' ';
            }
         }else{
            if(!(i&1)){
               v++;
            }
         }
         if(cur > r){
            cout << '\n';
            return;
         }
      }
   }
   // cout << '\n';
   // cout << cur << '\n';
   if(cur<r){
      cout << "1";
   }
   cout << '\n';
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