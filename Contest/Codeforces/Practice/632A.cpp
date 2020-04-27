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
   int n,p;
   cin >> n >> p;
   vector<string> s(n);
   for(int i=n-1;i>=0;i--){
      cin >> s[i];
   }
   assert(s[0] == "halfplus");
   int cur = 1,sm = 1;
   f(i,1,n){
      if(s[i] == "half"){
         sm = sm*2;
      }else{
         sm = sm*2+1;
         cur++;
      }
   }
   int ans = p*sm-(cur*p)/2;
   cout << ans << '\n';
   return 0;
}