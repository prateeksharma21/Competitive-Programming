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
   vector<int> A(n+1);
   set<int> S;
   f(i,1,n+1){
      cin >> A[i];
      S.insert(A[i]);
   } 
   vector<pii> ans;
   for(auto &e : S){
      int cnt = (A[1] == e);
      vector<int> B = A;
      f(i,2,n+1){
         if(B[i] == e and B[i] == B[i-1]){
            B[i] = MOD;
            continue;
         }
         if(B[i] == e){
            cnt++;
         }
      }
      ans.pb({-cnt,e});
   }
   sort(all(ans));
   cout << ans[0].S << '\n';
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
