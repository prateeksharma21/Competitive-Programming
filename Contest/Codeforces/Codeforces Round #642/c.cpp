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
   int n;
   cin >> n;
   int ans = 0;
   while(n!=1){
      int cell = n*4-4;
      ans += (n/2)*cell;
      n-=2;
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