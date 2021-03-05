#ifdef Prateek
  #include "\Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector<string> s(n);
   for(string &i : s) {
      cin >> i;
   }

   auto is = [&](vector<string> S) {
      vector<pair<int, int>> mv;
      if(s[0][1] != S[0][1]) mv.push_back({1,2});
      if(s[1][0] != S[1][0]) mv.push_back({2,1});
      if(s[n-1][n-2] != S[n-1][n-2]) mv.push_back({n,n-1});
      if(s[n-2][n-1] != S[n-2][n-1]) mv.push_back({n-1,n});
      if(mv.size() > 2) return false;
      cout << mv.size() << '\n';
      for(auto [x,y] : mv) {
         cout << x << ' ' << y << '\n';
      }
      return true;
   };

   vector<string> S = s;
   S[0][1] = '0';
   S[1][0] = '0';
   S[n-1][n-2] = '1';
   S[n-2][n-1] = '1';
   if(is(S)) return;
   S[0][1] = '1';
   S[1][0] = '1';
   S[n-1][n-2] = '0';
   S[n-2][n-1] = '0';
   if(is(S)) return;
   assert(false);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
