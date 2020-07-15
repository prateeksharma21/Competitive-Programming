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
   int tt;
   cin >> tt;
   f(_,1,tt+1){
      cout << "Case #" << _ << ": ";
      int n,d;
      cin >> n >> d;
      vector<int> a(n);
      f(i,0,n){
         cin >> a[i];
      }
      int nxt = d;
      for(int i=n-1;i>=0;i--){
         int k = nxt/a[i];
         a[i] = k*a[i];
         nxt = a[i];
      }
      cout << a[0] << '\n';
   }
   return 0;
}