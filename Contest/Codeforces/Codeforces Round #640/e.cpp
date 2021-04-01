#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 8000 + 1;
 
int A[N];
int pre[N];
bool C[N];
int Cnt[N];
int n;
int ans;


void test(){
   cin >> n;
   f(i,1,n+1){
      C[i] = 0;
      Cnt[i] = 0;
   }
   f(i,1,n+1){
      cin >> A[i];
      Cnt[A[i]]++;      
      pre[i] = pre[i-1]+A[i];
   }
   ans = 0;
   f(i,0,n){
      f(j,i+2,n+1){
         if(pre[j]-pre[i]<=n){
            C[pre[j]-pre[i]] = 1;
         }
      }
   }
   f(i,1,n+1){
      if(C[i]){
         ans += Cnt[i];
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
