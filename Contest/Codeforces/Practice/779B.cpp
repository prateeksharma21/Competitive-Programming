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
   int k;
   string n;
   cin >> n >> k;
   int ans = 0;
   int c = 0,i = n.length()-1;
   while(c!=k and i>=0){
      if(n[i] == '0'){
         c++;
      }else{
         ans++;
      }
      i--;
   } 
   if(c == k)
      cout << ans;
   else
      cout << max((int)n.length()-1,1ll);
   return 0;
}