#ifdef Prateek
  #include "Prateek.h"
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
   string s;
   cin >> s;
   vector<pair<int, int>> cnt;
   int st = 0;
   string res = "";
   while(st<n and s[st] == '0') st++,res += '0';
   
   string ans = "";
   int en = n-1;
   while(en>=0 and s[en] == '1') en--,ans += '1';
   if(st < en){
      res += '0';
   }
   cout << res << ans<< '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
} 