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

int toint(string x){
   int v = 0;
   reverse(all(x));
   f(i,0,4){
      v += (x[i] == '1') * (1<<i);
   }
   return max(v,8ll);
}

void test(){
   int n;
   cin >> n;
   int tot = n*4;
   string t = "1001";
   string s = "";
   f(i,0,n){
      s += t;
   }
   int rem = n,j = tot-1;
   while(rem--){
      s[j] = '0';
      --j;
   }
   debug(s);
   f(i,0,tot){
      cout << toint(s.substr(i,4));
      i += 3;
   }
   cout << '\n';
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
