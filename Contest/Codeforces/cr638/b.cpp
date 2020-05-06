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
   int k,n;
   cin >> n >> k;
   vector<int> A(n);
   set<int> S;
   f(i,0,n){
      cin >> A[i];
      S.insert(A[i]);
   } 
   if(S.size()>k){
      cout << "-1\n";
      return;
   }
   vector<int> R(S.begin(),S.end());
   while(R.size()!=k){
      R.pb(1);
   }
   cout << k*n << '\n';
   f(i,0,n){
      for(auto &e : R){
         cout << e <<  ' ';
      }
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
