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
   int n,m;
   cin >> n >> m;
   vector<int> A(n);
   vector<int> cn(m+1),cnt(m+1);
   int one = 0;
   f(i,0,n){
      cin >> A[i];
      if(A[i] <= m){
         cn[A[i]]++;
      }
   }
   f(i,1,m+1){
      for(int j=i;j<=m;j+=i){
         cnt[j] += cn[i];
      }
   }
   int mx = 1,c = 0;
   f(i,1,m+1){
      if(cnt[i]>c){
         c = cnt[i];
         mx = i;
      }
   }
   cout << mx << ' ' << c << '\n';
   f(i,0,n){
      if(mx%A[i] == 0){
         cout << i+1 << ' ';
      }
   }
   return 0;
}