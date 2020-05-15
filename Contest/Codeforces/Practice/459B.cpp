#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define Fr(n) for(int i=0;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   int mx = 1,mn = 1e9;
   map<int,int> cnt;
   Fr(n){
      int x;
      cin >> x;
      cnt[x]++;
      mx = max(mx,x);
      mn = min(mn,x);
   }
   if(mx!=mn){
      cout << mx-mn << ' ' << cnt[mx]*cnt[mn];
   }else{
      cout << 0 << ' ' << n*(n-1)/2 << '\n';
   }
   return 0;
}