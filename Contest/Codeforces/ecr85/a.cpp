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
   vector<pii> a(n);
   f(i,0,n){
      cin >> a[i].F >> a[i].S;
   }
   f(i,0,n){
      if(a[i].F<a[i].S){
         cout << "NO\n";
         return;
      }
   }
   f(i,1,n){
      if(a[i].F<a[i-1].F or a[i].S<a[i-1].S){
         cout << "NO\n";
         return;
      }
      if(a[i].F-a[i-1].F<a[i].S-a[i-1].S){
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
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
