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
   int cur = 0;
   auto V = [&](int n){
      return (n*(n+1)*(2*n+1)/6+n*(n+1)/2)/2;
   };
   while(V(cur) <= n) cur++;      
   cout << cur-1 << '\n';
   return 0;
}