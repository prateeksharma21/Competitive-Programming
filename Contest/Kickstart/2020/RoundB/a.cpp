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
      int n;
      cin >> n;
      vector<int> a(n);
      f(i,0,n){
         cin >> a[i];
      }
      int ans = 0;
      f(i,1,n-1){
         if(a[i]>a[i-1] and a[i]>a[i+1]) ans++;
      }
      cout << ans << '\n';
   }
   return 0;
}