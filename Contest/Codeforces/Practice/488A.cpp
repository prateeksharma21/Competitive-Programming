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
   int a;
   cin >> a;
   int b = a+1;
   auto lucky = [&](int n){
      n = abs(n);
      string s = to_string(n);
      for(auto &e : s) if(e == '8') return true;
      return false;
   };
   while(!lucky(b)) b++;
   cout << b-a << '\n';
   return 0;
}