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
const int MOD = 1e9+7, N = 2e5 + 10; 

int A[N],U[N],V[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   f(i,1,n+1){
      cin >> A[i];
   }
   sort(A+1,A+1+n);
   while(q--){
      int l,r;
      cin >> l >> r;
      ++U[l];
      --U[r+1];
   }
   int c = 0;
   f(i,1,n+1){
      c += U[i];
      V[i] = c;
   }
   sort(V+1,V+1+n);
   int ans = 0;
   f(i,1,n+1){
      ans += V[i]*A[i];
   }
   cout << ans << '\n';
   return 0;
}