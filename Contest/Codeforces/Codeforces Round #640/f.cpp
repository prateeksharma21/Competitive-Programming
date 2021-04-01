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
   int n0,n1,n2;
   cin >> n0 >> n1 >> n2;
   string ans(n0+n1+n2+1,'0');
   if(!n0 and !n2){
      f(i,0,ans.size()){
         ans[i++] = '1';
      }
      cout << ans << '\n';
      return;
   }
   if(!n0 and !n1){
      cout << string(ans.size(),'1') << '\n';
      return;
   }
   if(!n1 and !n2){
      cout << ans << '\n';
      return;
   }
   if(!n0){
      f(i,0,n2+1){
         ans[i] = '1';
      }
      f(i,n2+2,ans.size()){
         ans[i++] = '1';
      }
      cout << ans << '\n';
      return;
   }
   if(!n2){
      f(i,n0+1,ans.size()){
         ans[i++] = '1';
      }
      cout << ans << '\n';
      return;
   }
   n1--;
   f(i,n0+1,n0+1+n2+1){
      ans[i] = '1';
   }
   f(i,n0+1+n2+2,ans.size()){
      ans[i++] = '1';
   }
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
