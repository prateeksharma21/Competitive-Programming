#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int C[15];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,l,r,x;
   cin >> n >> l >> r >> x;
   f(i,0,n){
      cin >> C[i];
   }
   int ans = 0;
   f(i,0,(1<<n)){
      if(__builtin_popcount(i)<2) continue;
      int sm = 0,mx = 0,mn = 1e9;
      f(j,0,n){
         if(i&(1<<j)){
            sm += C[j];
            mx = max(mx,C[j]);
            mn = min(mn,C[j]);
         }
      }
      ans += (l<=sm and sm<=r and mx-mn>=x);
   }
   cout << ans << '\n';
   return 0;
}