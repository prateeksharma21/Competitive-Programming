#include <bits/stdc++.h>
using namespace std;
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
   int t0 = count(all(s),'0'),t1 = count(all(s),'1');
   int ans = min(t0,t1);
   int c0 = 0,c1 = 0;
   int n = s.length();
   f(i,0,n){
      c0 += (s[i] == '0');
      c1 += (s[i] == '1');
      t0 -= (s[i] == '0');
      t1 -= (s[i] == '1');
      ans = min(ans,i+1-c0+n-i-1-t1);
      ans = min(ans,i+1-c1+n-i-1-t0);
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
