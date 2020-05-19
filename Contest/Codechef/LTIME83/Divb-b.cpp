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
   int n,s;
   cin >> n >> s;
   vector<int> A,B;
   vector<int> P(n+1);
   f(i,1,n+1){
      cin >> P[i];
   } 
   int rem = 100-s;
   f(i,1,n+1){
      int x;
      cin >> x;
      if(x){
         A.pb(P[i]);
      }else{
         B.pb(P[i]);
      }
   }
   sort(all(A));
   sort(all(B));
   if(A.empty() or B.empty()){
      cout << "no\n";
      return;
   }
   if(A[0]+B[0]<=rem){
      cout << "yes\n";
   }else{
      cout << "no\n";
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