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
 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

void test(){
   string s;
   cin >> s;
   int n = s.length();
   vector<int> pos[4];
   f(i,0,n){
      pos[s[i]-'0'].pb(i);
   }
   int ans = 1e18;
   f(i,0,n){
      auto k1 = lower_bound(all(pos[1]),i);
      auto k2 = lower_bound(all(pos[2]),i);
      auto k3 = lower_bound(all(pos[3]),i);
      if(k1 == pos[1].end() or k2 == pos[2].end() or k3 == pos[3].end()){
         continue;
      }
      ans = min(ans,max({*k1,*k2,*k3})-i+1);
   }
   if(ans == 1e18){
      cout << "0\n";
   }else{
      cout << ans << '\n';
   }
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
