#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   if(n<=2){
      return cout << "No",0;
   }
   cout << "Yes\n";
   cout << n/2 << ' ';
   f(i,2,n+1){
      cout << i++ << ' ';
   }  
   cout << '\n';
   cout << (n+1)/2 << ' ';
   f(i,1,n+1){
      cout << i++ << ' ';
   }
   cout << '\n';
   return 0;
}