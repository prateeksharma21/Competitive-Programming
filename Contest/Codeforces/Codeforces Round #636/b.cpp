#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   if((n/2)&1){
      cout << "NO\n";
      return;
   }
   cout << "YES\n";
   int cur = 2,d = 2;
   f(i,0,n/2){
      cout << cur << ' ';
      if(d == 2) d = 4;
      else d = 2;
      cur += d;
   }
   cur = 3,d = 4;
   f(i,0,n/2){
      cout << cur << ' ';
      if(d == 2) d = 4;
      else d = 2;
      cur += d;
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