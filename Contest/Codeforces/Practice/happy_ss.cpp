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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   vector<int> A(n+1),V(m+1),pos[m+1];
   f(i,1,n+1) cin >> A[i],pos[A[i]].pb(i);
   f(i,1,m+1) cin >> V[i];
   int q;
   cin >> q;
   
   while(q--){
      int l,r;
      int c = 1;
      cin >> l >> r;
      f(i,1,m+1){
         int v = upper_bound(all(pos[i]),r)-lower_bound(all(pos[i]),l);
         c &= (v == V[i] or v == 0);
      }
      cout << c << '\n';
   }
   return 0;
}