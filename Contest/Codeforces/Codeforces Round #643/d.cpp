#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,s;
   cin >> n >> s;
   if(s>=2*n){
      cout << "YES\n";
      int sm = 0;
      f(i,1,n){
         cout << 2 << ' ';
         sm += 2;
      }
      cout << s-sm << '\n' << "1\n";
      return 0;
   }
   cout << "NO\n";
   return 0;
}