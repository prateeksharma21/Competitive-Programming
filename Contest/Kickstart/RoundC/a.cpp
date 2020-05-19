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
   int n,k;
   cin >> n >> k;
   vector<int> A(n);
   f(i,0,n){
      cin >> A[i];
   }
   int ans = 0;
   f(i,0,n){
      int cnt = 0;
      int v = k,j = i;
      while(j<n and v and A[j] == v){
         j++;
         v--;
      }
      if(v == 0){
         ans++;
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
   f(i,1,tt+1){
      cout << "Case #" << i << ": ";
      test();
   }
   return 0;
}