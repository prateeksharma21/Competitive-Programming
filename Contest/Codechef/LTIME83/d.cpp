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
   int tt;
   cin >> tt;
   int n,k;
   cin >> n >> k;
   vector<int> A(n+1),pre(n+1);
   f(i,1,n+1){
      cin >> A[i];
      pre[i] = pre[i-1]^A[i];
   }
   vector<pii> R(n+1);
   f(i,1,n+1){
      cin >> R[i].F >> R[i].S;
   }
   f(i,2,k+1){
      f(i,1,n+1){
         A[i] = pre[R[i].S]^pre[R[i].F-1];
      }
      f(i,1,n+1){
         pre[i] = pre[i-1]^A[i];
      }
   }
   f(i,1,n+1){
      cout << A[i] << ' ';
   }
   cout << '\n';
   return 0;
}