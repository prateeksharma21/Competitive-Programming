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
   int n,k;
   cin >> n >> k;
   string s;
   cin >> s;
   int c[2] = {0,0};
   int ans = 0;
   int j = 0;
   f(i,0,n){
      while(j<n and min(c[0],c[1])<=k){
         c[s[j]-'a']++;
         j++;
      }
      if(min(c[0],c[1])<=k)
         ans = max(ans,j-i);
      else
         ans = max(ans,j-i-1);
      c[s[i]-'a']--;
   }
   cout << ans << '\n';
   return 0;
}