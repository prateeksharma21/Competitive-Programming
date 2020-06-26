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
   string s;
   cin >> s;
   int n = s.length();
   vector<int> pre(n+1);
   int mn = 0;
   f(i,1,n+1){
      pre[i] = pre[i-1];
      if(s[i-1] == '-') pre[i]--;
      else pre[i]++;
      mn = min(mn,pre[i]);
   }
   int fin = -mn;
   map<int,int> pos;
   for(int i = n; i >= 1; i--){
      pos[pre[i]] = i;
   }
   int ans = n;
   f(i,0,fin){
      int p = pos[-(i+1)];
      ans += p;
   }
   cout << ans << '\n';
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
