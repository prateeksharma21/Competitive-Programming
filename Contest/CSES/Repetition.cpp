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
   string s;
   cin >> s;
   int n = s.length();
   int ans = 1,c = 1;
   f(i,1,n){
      if(s[i] == s[i-1]){
         c++;
      }else{
         c = 1;
      }
      ans = max(ans,c);
   }
   cout << ans << '\n';
   return 0;
} 