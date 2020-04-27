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
   int n;
   cin >> n;
   vector<int> a(n),A(n);
   f(i,0,n){
      cin >> a[i];
      A[i] = (a[i]>0);
   }
   int ans = 0;
   for(int i=0,j;i<n;i = j){
      j = i;
      int mx = -1e18;
      while(j<n and A[j] == A[i]){
         mx = max(mx,a[j]);
         j++;
      }
      ans += mx;
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
