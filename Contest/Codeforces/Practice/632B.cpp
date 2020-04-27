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
   int n;
   cin >> n;
   vector<int> P(n);
   for(auto &p : P){
      cin >> p;
   }
   string s;
   cin >> s;
   int ans = 0;
   f(i,0,n){
      ans += P[i]*(s[i] == 'B');
   }
   int cA = 0,cB = 0;
   int res = ans;
   f(i,0,n){
      cA += P[i]*(s[i] == 'A');
      cB += P[i]*(s[i] == 'B');
      res = max(res,ans+cA-cB);
   }
   reverse(all(s));
   reverse(all(P));
   cA = 0,cB = 0;
   f(i,0,n){
      cA += P[i]*(s[i] == 'A');
      cB += P[i]*(s[i] == 'B');
      res = max(res,ans+cA-cB);
   }
   cout << res << '\n';
   return 0;
}