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
   if(n<=3){
      cout << "-1\n";
      return;
   }
   deque<int> A;
   A.pb(3);
   A.pb(1);
   A.pb(4);
   A.pb(2);
   f(i,5,n+1){
      if(i&1){
         A.pb(i);
      }else{
         A.push_front(i);
      }
   }
   for(auto &e : A){
      cout << e << ' ';
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
