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
   vector<int> A(n);
   map<int,vector<int>> P;
   vector<int> B;
   f(i,0,n){
      cin >> A[i];
      if(P[A[i]].empty()) B.pb(A[i]);
      P[A[i]].pb(i);
   }
   int ans = 1,lst = -1;
   sort(all(B));
   for(auto &e : B){
      auto k = upper_bound(all(P[e]),lst);
      if(k == P[e].end()){
         ans++;
         lst = P[e][0];
      }else{
         lst = *k;
      }
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
